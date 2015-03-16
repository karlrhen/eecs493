#include "mainwindow.h"
#include "boximage.h"

#include <QWidget>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>
#include <QFrame>
#include <QUndoStack>
#include <QAction>
#include <QMessageBox>
#include <QScrollArea>
#include <QTimer>
#include <QUndoView>
#include <QPushButton>
#include <QClipboard>

static const int BUTTON_SIZE = 150;

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
   undoStack = new QUndoStack();
   QUndoView *undoView = new QUndoView(undoStack);
   undoView->setWindowTitle(tr("Command List"));
   undoView->show();
   undoView->setAttribute(Qt::WA_QuitOnClose, false);

   clipBoard = QApplication::clipboard();

   newAction = new QAction("&New",this);
   newAction->setShortcuts(QKeySequence::New);

   openAction = new QAction("&Open",this);
   openAction->setShortcuts(QKeySequence::Open);

   saveAction = new QAction("&Save",this);
   saveAction->setShortcuts(QKeySequence::Save);

   saveAsAction = new QAction("S&ave as",this);
   saveAsAction->setShortcuts(QKeySequence::SaveAs);

   quitAction = new QAction("&Quit",this);
   quitAction->setShortcuts(QKeySequence::Quit);

   cutAction = new QAction("&Cut",this);
   cutAction->setShortcuts(QKeySequence::Cut);

   copyAction = new QAction("&Copy",this);
   copyAction->setShortcuts(QKeySequence::Copy);

   pasteAction = new QAction("&Paste",this);
   pasteAction->setShortcuts(QKeySequence::Paste);

   addCollectionAction = new QAction("Add &Collection",this);
   addCollectionAction->setShortcut(QKeySequence::SelectAll);

   addImageAction = new QAction("Add &Image",this);
   addImageAction->setShortcut(QKeySequence::Italic);

   deleteAllAction = new QAction("&Delete All Images",this);
   deleteAllAction->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_D));

   deleteImageAction = new QAction("&Delete Image",this);
   deleteImageAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));


   QMenu* fileMenu = this->menuBar()->addMenu("&File");
   fileMenu->addAction(newAction);
   fileMenu->addAction(openAction);
   fileMenu->addSeparator();
   fileMenu->addAction(saveAction);
   fileMenu->addAction(saveAsAction);
   fileMenu->addSeparator();
   fileMenu->addAction(quitAction);

   QMenu* editMenu = this->menuBar()->addMenu("&Edit");
   QAction *temp = undoStack->createUndoAction(editMenu);
   temp->setShortcut(QKeySequence::Undo);
   editMenu->addAction(temp);
   temp = undoStack->createRedoAction(editMenu);
   temp->setShortcut(QKeySequence::Redo);
   editMenu->addAction(temp);
   editMenu->addSeparator();
   editMenu->addAction(cutAction);
   editMenu->addAction(copyAction);
   editMenu->addAction(pasteAction);

   QMenu* imageMenu = this->menuBar()->addMenu("&Images");
   imageMenu->addAction(addCollectionAction);
   imageMenu->addAction(addImageAction);
   imageMenu->addSeparator();
   imageMenu->addSeparator();
   imageMenu->addAction(deleteAllAction);
   imageMenu->addAction(deleteImageAction);



   QWidget *leftWidget = new QWidget();
   QGridLayout *leftLayout = new QGridLayout();
   leftWidget->setLayout(leftLayout);

   // Create Buttons
   QPushButton *add_collection_button = new QPushButton("Add Collection");
   QPushButton *add_image_button      = new QPushButton("Add Image");
   QPushButton *remove_all_button     = new QPushButton("Remove All");

   add_collection_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   add_image_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   remove_all_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

   // Add Buttons to Layout
   leftLayout->addWidget(add_collection_button, 1, 0);
   leftLayout->addWidget(add_image_button,      2, 0);
   leftLayout->addWidget(remove_all_button,     3, 0);

   leftLayout->setVerticalSpacing(4);

   button       = NULL;


   QScrollArea *scrollArea = new QScrollArea();
   scrollArea->setWidgetResizable(1);
   boxImage = new BoxImage(undoStack, clipBoard, addCollectionAction, addImageAction, this);
   boxImage->setMaximumWidth(BUTTON_SIZE*5+20);
   boxImage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
   scrollArea->setWidget(boxImage);


   QList<int> sizeList = QList<int>() << 200 << BUTTON_SIZE*5;

   QSplitter *screen_splitter = new QSplitter();
   screen_splitter->addWidget(leftWidget);
   screen_splitter->addWidget(scrollArea);

   this->setCentralWidget(screen_splitter);
   this->resize(BUTTON_SIZE*5+200,400);


   connect (quitAction,          SIGNAL(triggered()), boxImage, SLOT(quit()));
   connect (addCollectionAction, SIGNAL(triggered()), boxImage, SLOT(addCollectionCallback()));
   connect (addImageAction,      SIGNAL(triggered()), boxImage, SLOT(addImageCallback()));
   connect (deleteAllAction,     SIGNAL(triggered()), boxImage, SLOT(deleteAllCallback()));
   connect (deleteImageAction,   SIGNAL(triggered()), boxImage, SLOT(deleteImageCallback()));
   connect (deleteAllAction,     SIGNAL(triggered()), this,     SLOT(clearButton()));
   connect (deleteImageAction,   SIGNAL(triggered()), this,     SLOT(clearButton()));
   connect (cutAction,           SIGNAL(triggered()), boxImage, SLOT(cutCallback()));
   connect (copyAction,          SIGNAL(triggered()), boxImage, SLOT(copyCallback()));
   connect (pasteAction,         SIGNAL(triggered()), boxImage, SLOT(pasteCallback()));

   connect (clipBoard,                 SIGNAL(dataChanged()), this, SLOT(clipBoardCallback()));
   connect (boxImage->buttonGroup,     SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonEmit(QAbstractButton*)));

   connect(newAction,   SIGNAL(triggered()),this,SLOT(notYetCallback()));
   connect(openAction,  SIGNAL(triggered()),this,SLOT(notYetCallback()));
   connect(saveAction,  SIGNAL(triggered()),this,SLOT(notYetCallback()));
   connect(saveAsAction,SIGNAL(triggered()),this,SLOT(notYetCallback()));

}

void MainWindow::notYetCallback()
{
   QMessageBox message;
   message.setText("Will be implemented at a later date.");
   message.exec();
}

void MainWindow::buttonEmit(QAbstractButton *ebutton)
{
    if(ebutton == button)
    {
        boxImage->buttonGroup->setExclusive(false);
        button->setChecked(false);
        button = NULL;
        boxImage->buttonGroup->setExclusive(false);
    }
    else
    {
        button = ebutton;
    }
    setupPreview(button);
}

void MainWindow::clearButton()
{
    if(!button)
    {
        boxImage->buttonGroup->setExclusive(false);
        button = NULL;
        boxImage->buttonGroup->setExclusive(false);
    }
    setupPreview(button);
}

void MainWindow::clipBoardCallback()
{
    if(clipBoard->image().isNull())
    {
        pasteAction->setEnabled(false);
    }
    else
    {
        pasteAction->setEnabled(true);
    }
}

void MainWindow::setupPreview(QAbstractButton *button)
{
    if(button == NULL)
    {
        previewLabel->clear();
        previewLabel->setText("There is no preview available");
        setCCP(true);
        if(timer->isActive())
        {
            stopCallback();
            playCallback();
        }
        return;
    }
    else
    {
        QPixmap pic = button->icon().pixmap(PIC_SIZE, PIC_SIZE).scaled(PREVIEW_SIZE, PREVIEW_SIZE, Qt::KeepAspectRatio);
        previewLabel->setPixmap(pic);
        setCCP(true);
        if(timer->isActive())
        {
            stopCallback();
            playCallback();
        }

    }
}

void MainWindow::setCCP(bool enabled)

{
    deleteImageAction->setEnabled(enabled);
    copyAction->setEnabled(enabled);
    cutAction->setEnabled(enabled);

}

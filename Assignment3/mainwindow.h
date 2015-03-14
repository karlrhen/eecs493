#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QSplitter>
#include <QTimer>
#include "boximage.h"

static const int PREVIEW_SIZE = 300;
static const int PIC_SIZE   = 144;

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);

protected:
   QLabel          *previewLabel;
   QAbstractButton *button;
   QDockWidget     *dock;
   QSplitter       *splitter;
   BoxImage        *boxImage;
   QUndoStack      *undoStack;
   QClipboard      *clipBoard;
   QTimer          *timer;

   QAction *quitAction;
   QAction *addFlickrCollectionAction;
   QAction *addCollectionAction;
   QAction *addImageAction;
   QAction *deleteAllAction;
   QAction *deleteImageAction;
   QAction *newAction;
   QAction *openAction;
   QAction *saveAction;
   QAction *saveAsAction;
   QAction *cutAction;
   QAction *copyAction;
   QAction *pasteAction;
   QAction *undoAction;
   QAction *redoAction;
   QAction *playAction;
   QAction *stopAction;

public slots:
   void notYetCallback();
   void buttonEmit(QAbstractButton *ebutton);
   void clearButton();
   void clipBoardCallback();
   void setupPreview(QAbstractButton *button);
   void setCCP(bool enabled);
  // BoxImage* getCurrentImageGrid();
   void playCallback();
   void stopCallback();
   void updatePlayback();
private:
   QLabel *currentImage;
   QAbstractButton *nextImage;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "boximage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create Box Image Widget & Set Constraints
    right_layout = new QGridLayout();
    box_image_widget = new BoxImage(this,right_layout);
    box_image_widget->setMaximumWidth(770);

    // Create Scroll Area
    scroll_area = new QScrollArea();
    scroll_area->setWidgetResizable(true);

    // Create Buttons
    add_collection_button = new QPushButton("Add Collection");
    add_image_button      = new QPushButton("Add Image");
    remove_all_button     = new QPushButton("Remove All");

    add_collection_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    add_image_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    remove_all_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // Create QClipboard
    clip_board = QApplication::clipboard();

    // Create Button & Action Functionality
    create_actions();
    create_button_content();
    create_action_content();
    // Create Layout
    left_layout = new QGridLayout();

    // Create QWidget
    left_widget = new QWidget();

    // Create QSplitter
    screen_splitter = new QSplitter();

    // Add Buttons to Layout
    left_layout->addWidget(add_collection_button, 1, 0);
    left_layout->addWidget(add_image_button,      2, 0);
    left_layout->addWidget(remove_all_button,     3, 0);

    // Set Pixel Length
    left_layout->setVerticalSpacing(4);

    // Set Layout
    left_widget->setLayout(left_layout);
    box_image_widget->setLayout(right_layout);
    scroll_area->setWidget(box_image_widget);

    // Create Menus
    create_menu_bars();

    // Add Left & Right Widget to QSplitter
    screen_splitter->addWidget(left_widget);
    screen_splitter->addWidget(scroll_area);
    // Set Central Widget
    this->setCentralWidget(screen_splitter);

}

void MainWindow::create_menu_bars()
{
    file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->addAction(new_action);
    file_menu->addAction(open_action);
    file_menu->addSeparator();
    file_menu->addAction(save_action);
    file_menu->addAction(save_as_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);

    edit_menu = menuBar()->addMenu(tr("&Edit"));
    edit_menu->addAction(undo_action);
    edit_menu->addAction(redo_action);
    edit_menu->addSeparator();
    edit_menu->addAction(add_collection_action);
    edit_menu->addAction(add_image_action);
    edit_menu->addAction(remove_all_images_action);
    //edit_menu->addAction(cut_action);
    //edit_menu->addAction(copy_action);
    //edit_menu->addAction(paste_action);
    edit_menu->addSeparator();

    /*
    images_menu = menuBar()->addMenu(tr("&Images"));
    images_menu->addAction(add_collection_action);
    images_menu->addAction(add_image_action);
    images_menu->addAction(remove_all_images_action);
    */
}

void MainWindow::create_actions()
{
    new_action = new QAction(tr("New"), this);
    new_action->setShortcuts(QKeySequence::New);

    open_action = new QAction(tr("Open"), this);
    open_action->setShortcuts(QKeySequence::Open);

    save_action = new QAction(tr("Save"), this);
    save_action->setShortcuts(QKeySequence::Save);

    save_as_action = new QAction(tr("SaveAs"), this);
    save_as_action->setShortcuts(QKeySequence::SaveAs);

    exit_action = new QAction(tr("Exit"), this);
    exit_action->setShortcuts(QKeySequence::Quit);

    undo_action = new QAction(tr("Undo"), this);
    undo_action->setShortcuts(QKeySequence::Undo);

    redo_action = new QAction(tr("Redo"), this);
    redo_action->setShortcuts(QKeySequence::Redo);

    cut_action = new QAction(tr("Cut"), this);
    cut_action->setShortcuts(QKeySequence::Cut);

    copy_action = new QAction(tr("Copy"), this);
    copy_action->setShortcuts(QKeySequence::Copy);

    paste_action = new QAction(tr("Paste"), this);
    paste_action->setShortcuts(QKeySequence::Paste);

    add_collection_action = new QAction(tr("Add Collection"), this);
    add_collection_action->setShortcuts(QKeySequence::Bold);

    add_image_action = new QAction(tr("Add Image"), this);
    add_image_action->setShortcuts(QKeySequence::Italic);


    remove_all_images_action = new QAction(tr("Remove All Images"), this);
    remove_all_images_action->setShortcuts(QKeySequence::Underline);
}

void MainWindow::create_button_content()
{
    connect(add_collection_button, SIGNAL(clicked()), box_image_widget, SLOT(assign_add_collection_button_content()));
    connect(add_image_button,      SIGNAL(clicked()), box_image_widget, SLOT(assign_add_image_button_content()));
    connect(remove_all_button,     SIGNAL(clicked()), box_image_widget, SLOT(assign_remove_all_button_content()));
}
void MainWindow::create_action_content()
{
    connect (new_action,               SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (open_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (save_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (save_as_action,           SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (exit_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_quit_action()));
    connect (undo_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (redo_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_not_implemented_msg()));
    connect (cut_action,               SIGNAL(triggered()), box_image_widget, SLOT(assign_cut_action()));
    connect (copy_action,              SIGNAL(triggered()), box_image_widget, SLOT(assign_copy_action()));
    connect (paste_action,             SIGNAL(triggered()), box_image_widget, SLOT(assign_paste_action()));
    connect (add_collection_action,    SIGNAL(triggered()), box_image_widget, SLOT(assign_add_collection_button_content()));
    connect (add_image_action,         SIGNAL(triggered()), box_image_widget, SLOT(assign_add_image_button_content()));
    connect (remove_all_images_action, SIGNAL(triggered()), box_image_widget, SLOT(assign_remove_all_button_content()));

    connect (clip_board, SIGNAL(dataChanged()), this, SLOT(assign_clip_board_action()));

}

void MainWindow::assign_clip_board_action()
{
    clip_board->image().isNull() ? paste_action->setEnabled(false):paste_action->setEnabled(true);
}

MainWindow::~MainWindow()
{

}

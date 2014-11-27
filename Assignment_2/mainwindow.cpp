#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create Buttons
    add_collection_button = new QPushButton("Add Collection");
    add_image_button      = new QPushButton("Add Image");
    remove_all_button     = new QPushButton("Remove All");

    // Create Layout
    left_layout = new QGridLayout();

    // Create QWidget
    left_widget = new QWidget();

    // Add Buttons to Layout
    left_layout->addWidget(add_collection_button, 1, 0);
    left_layout->addWidget(add_image_button,      2, 0);
    left_layout->addWidget(remove_all_button,     3, 0);

    // Set Layout & Central Widget
    left_widget->setLayout(left_layout);
    this->setCentralWidget(left_widget);

}

void MainWindow::create_button_content()
{

}

void MainWindow::assign_add_collection_button_content()
{

}

void MainWindow::assign_add_image_button_content()
{

}

void MainWindow::assign_remove_all_button_content()
{

}

MainWindow::~MainWindow()
{

}

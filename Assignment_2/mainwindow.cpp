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

    //Create Temp Buttons, Temp Widget, & Temp Layout
    QPushButton *temp_button_one   = new QPushButton("Temp 1");
    QPushButton *temp_button_two   = new QPushButton("Temp 2");
    QPushButton *temp_button_three = new QPushButton("Temp 3");
    QWidget *right_widget = new QWidget;
    QGridLayout *right_layout = new QGridLayout();

    // Add Temp Buttons to Layout
    right_layout->addWidget(temp_button_one,   1, 0);
    right_layout->addWidget(temp_button_two,   2, 0);
    right_layout->addWidget(temp_button_three, 3, 0);

    // Set Temp Layout
    right_widget->setLayout(right_layout);

    // Add Left & Right Widget to QSplitter
    screen_splitter->addWidget(left_widget);
    screen_splitter->addWidget(right_widget);

    // Set Central Widget
    this->setCentralWidget(screen_splitter);




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

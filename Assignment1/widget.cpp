#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Create Buttons
    button_one   = new QPushButton("button 1");
    button_two   = new QPushButton("button 2");
    button_three = new QPushButton("button 3");
    button_four  = new QPushButton("button 4");
    button_five  = new QPushButton("button 5");
    button_six   = new QPushButton("button 6");
    button_seven = new QPushButton("quit");

    // Create Grid Layout
    grid_layout = new QGridLayout();

    // Add Buttons To Grid Layout
    grid_layout->addWidget(button_one,   1, 1);
    grid_layout->addWidget(button_two,   1, 2);
    grid_layout->addWidget(button_three, 1, 3);
    grid_layout->addWidget(button_four,  2, 1);
    grid_layout->addWidget(button_five,  2, 2);
    grid_layout->addWidget(button_six,   2, 3);
    grid_layout->addWidget(button_seven, 3, 2);

    // Set Layout
    this->setLayout(grid_layout);

    // Add Button Fuctionality
    create_button_content();
}

void Widget::create_button_content()
{
    connect(button_one,   SIGNAL(clicked()), this, SLOT(assign_button_one_content()));
    connect(button_two,   SIGNAL(clicked()), this, SLOT(assign_button_two_content()));
    connect(button_three, SIGNAL(clicked()), this, SLOT(assign_button_three_content()));
    connect(button_four,  SIGNAL(clicked()), this, SLOT(assign_button_four_content()));
    connect(button_five,  SIGNAL(clicked()), this, SLOT(assign_button_five_content()));
    connect(button_six,   SIGNAL(clicked()), this, SLOT(assign_button_six_content()));
    connect(button_seven, SIGNAL(clicked()), this, SLOT(assign_button_seven_content()));

}

void Widget::assign_button_one_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Little Piggy went to market");
    button_message->exec();

}

void Widget::assign_button_two_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Little Piggy went home");
    button_message->exec();

}

void Widget::assign_button_three_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Little Piggy had roast beef");
    button_message->exec();

}

void Widget::assign_button_four_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Little Piggy had none");
    button_message->exec();

}

void Widget::assign_button_five_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Little Piggy went wee wee wee");
    button_message->exec();

}

void Widget::assign_button_six_content()
{
    QMessageBox *button_message = new QMessageBox();
    button_message->setText("This Last Little Piggy was OWT AF");
    button_message->exec();

}

void Widget::assign_button_seven_content()
{
    this->close();
}

Widget::~Widget()
{

}

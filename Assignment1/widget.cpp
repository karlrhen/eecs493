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

    // Create QButtonGroup
    button_group = new QButtonGroup();

    // Add Buttons to QButtonGroup
    button_group->addButton(button_one  ,1);
    button_group->addButton(button_two  ,2);
    button_group->addButton(button_three,3);
    button_group->addButton(button_four ,4);
    button_group->addButton(button_five ,5);
    button_group->addButton(button_six  ,6);

    // Create Grid Layout
    grid_layout = new QGridLayout();

    // Create QSpace
    add_space = new QSpacerItem(15,15,QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Add Buttons To Grid Layout
    grid_layout->addWidget(button_group->button(1), 1, 1);
    grid_layout->addWidget(button_group->button(2), 1, 2);
    grid_layout->addWidget(button_group->button(3), 1, 3);
    grid_layout->addWidget(button_group->button(4), 2, 1);
    grid_layout->addWidget(button_group->button(5), 2, 2);
    grid_layout->addWidget(button_group->button(6), 2, 3);
    grid_layout->addItem(add_space, 3, 2);
    grid_layout->addWidget(button_seven           , 4, 2);

    // Set Layout
    this->setLayout(grid_layout);

    // Add Button Fuctionality
    connect(button_group, SIGNAL(buttonClicked(int)), this, SLOT(assign_button_content(int)));
    connect(button_seven, SIGNAL(clicked()),          this, SLOT(assign_quit_button_content()));
}



void Widget::assign_button_content(int button_index)
{
    // Create QMessage Box
    button_message = new QMessageBox();

    //Set the Text of the QMessageBox
    switch(button_index)
    {
        case 1:
            button_message->setText("this little piggy went to market");
            button_message->exec();
            break;
        case 2:
            button_message->setText("this little piggy stayed home");
            button_message->exec();
            break;
        case 3:
            button_message->setText("this little piggy had roast beef");
            button_message->exec();
            break;
        case 4:
            button_message->setText("this little piggy had none");
            button_message->exec();
            break;
        case 5:
            button_message->setText("this little piggy went wee wee wee wee wee, all the way home");
            button_message->exec();
            break;
        case 6:
            button_message->setText("this little piggy had 6 toes");
            button_message->exec();
            break;
        default:
            break;
    }
}



void Widget::assign_quit_button_content()
{
    this->close();
}

Widget::~Widget()
{

}

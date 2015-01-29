#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVariant>
#include <QSpacerItem>
#include <QButtonGroup>
#include <QMessageBox>

using namespace std;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
   // Buttons to be Displayed
   QPushButton *button_one;
   QPushButton *button_two;
   QPushButton *button_three;
   QPushButton *button_four;
   QPushButton *button_five;
   QPushButton *button_six;
   QPushButton *button_seven;

   QButtonGroup *button_group;
   QGridLayout  *grid_layout;
   QMessageBox  *button_message;
   QSpacerItem  *add_space;

private slots:
    void assign_button_content(int button_index);
    void assign_quit_button_content();
};

#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void create_button_content();
    ~Widget();

private:
   QPushButton *button_one;
   QPushButton *button_two;
   QPushButton *button_three;
   QPushButton *button_four;
   QPushButton *button_five;
   QPushButton *button_six;
   QPushButton *button_seven;

   QGridLayout *grid_layout;

private slots:
    void assign_button_one_content();
    void assign_button_two_content();
    void assign_button_three_content();
    void assign_button_four_content();
    void assign_button_five_content();
    void assign_button_six_content();
    void assign_button_seven_content();

};

#endif // WIDGET_H

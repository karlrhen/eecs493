#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void create_button_content();
    ~MainWindow();

private:
    QGridLayout *left_layout;

    QWidget *left_widget;

    QPushButton *add_collection_button;
    QPushButton *add_image_button;
    QPushButton *remove_all_button;

private slots:
    void assign_add_collection_button_content();
    void assign_add_image_button_content();
    void assign_remove_all_button_content();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QScrollArea>

class BoxImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    BoxImage *box_image_widget;
    ~MainWindow();

private:
    void create_button_content();
    void create_action_content();
    void create_menu_bars();
    void create_actions();

    QGridLayout *left_layout;
    QGridLayout *right_layout;
    QWidget     *left_widget;
    QSplitter   *screen_splitter;
    QScrollArea *scroll_area;

    QPushButton *add_collection_button;
    QPushButton *add_image_button;
    QPushButton *remove_all_button;

    QClipboard *clip_board;

    QMenu *file_menu;
    QMenu *edit_menu;
   // QMenu *images_menu;

    QAction *new_action;
    QAction *open_action;
    QAction *save_action;
    QAction *save_as_action;
    QAction *exit_action;

    QAction *undo_action;
    QAction *redo_action;
    QAction *cut_action;
    QAction *copy_action;
    QAction *paste_action;

    QAction *add_collection_action;
    QAction *add_image_action;
    QAction *remove_all_images_action;

private slots:
    void assign_clip_board_action();

};

#endif // MAINWINDOW_H

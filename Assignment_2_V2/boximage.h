#ifndef BOXIMAGE_H
#define BOXIMAGE_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QGridLayout>
#include <QVector>
#include <QMimeData>
#include <QStringList>
#include <QDebug>
#include <QToolButton>
#include <QButtonGroup>
#include <QUndoCommand>
#include <QClipboard>
#include "mainwindow.h"
#include "addimagecommand.h"
#include <iostream>

const int BUTTON_SIZE = 150;
const int IMAGE_SIZE  = 144;

class BoxImage : public QWidget
{
    Q_OBJECT

public:
    explicit BoxImage(QWidget *parent = 0,
                      QGridLayout *_image_grid_layout = 0);

private:
    QFileDialog  *open_directory;
    QLabel       *image_label;
    QToolButton  *image_tool_button;
    QButtonGroup *image_button_group;
    QGridLayout  *image_grid_layout;
    QDir         *current_directory;

    int image_grid_layout_row;
    int image_grid_layout_col;
    int counter;

    QVector<QPixmap> image_list;
    QPixmap          image_pixmap;
    QStringList      directory_list;

    QToolButton *create_new_tool_button(QPixmap incoming_pixmap);

    QUndoStack *undo_stack;



public slots:
    void assign_add_collection_button_content();
    void assign_add_image_button_content(/*int insert_location*/);
    void assign_remove_all_button_content();
    void assign_not_implemented_msg();
    void assign_quit_action();
    void assign_copy_action();
    void assign_paste_action();
    void assign_cut_action();
    void insert_multiple_images(QVector<QPixmap> pixmapList, int insertLoc);
};

#endif // BOXIMAGE_H

#ifndef BOXIMAGE_H
#define BOXIMAGE_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <cassert>
#include <QGridLayout>
#include <QVector>
#include "mainwindow.h"

class BoxImage : public QWidget
{
    Q_OBJECT

public:
    explicit BoxImage(QWidget *parent = 0,
                      QGridLayout *_image_grid_layout = 0);

private:
    QFileDialog *open_directory;
    QLabel      *image_label;
    QGridLayout *image_grid_layout;
    QPixmap     image_pixmap;

    int image_grid_layout_size;
    int image_grid_layout_row;
    int image_grid_layout_col;



public slots:
    void assign_add_collection_button_content();
    void assign_add_image_button_content();
    void assign_remove_all_button_content();
};

#endif // BOXIMAGE_H

#include "boximage.h"

BoxImage::BoxImage(QWidget *parent, QGridLayout *_image_grid_layout) :
    QWidget(parent)
{
    // Get the Image Grid Layout
    image_grid_layout = new QGridLayout();
    image_grid_layout = _image_grid_layout;

    // Initialize size variables
    image_grid_layout_size = 0;
    image_grid_layout_row  = 0;
    image_grid_layout_col  = 0;

    // Set some specifications for BoxImage
    for (unsigned i= 0; i < 5; ++i)
    {
        image_grid_layout->setColumnMinimumWidth(i,IMAGE_SIZE + 8);
        image_grid_layout->setColumnStretch(i,0);
    }
      image_grid_layout->setOriginCorner(Qt::TopLeftCorner);
      image_grid_layout->setSpacing(0);

}

void BoxImage::assign_add_collection_button_content()
{
    // First open the directory
    open_directory = new QFileDialog();
    open_directory->getOpenFileNames(this,tr("Select one or more images to open"),"/","Images (*.png *.xpm *.jpg)");

}

void BoxImage::assign_add_image_button_content()
{
    // First open the directory
    open_directory = new QFileDialog();
    QString file_name = open_directory->getOpenFileName(this,tr("Open Image"),"/",tr("Image Files (*.png *.jpg *.bmp)"));

    // Create QPixmap & QLabel
    image_pixmap = QPixmap(file_name);
    image_pixmap.scaled(IMAGE_SIZE,IMAGE_SIZE);
    image_label  = new QLabel();

    // Set Pixmap
    image_label->setPixmap(image_pixmap);

    image_grid_layout->addWidget(image_label,image_grid_layout_row,image_grid_layout_col);

    image_grid_layout_size++;
    image_grid_layout_col++;

    if(image_grid_layout_col == 6)
    {
        image_grid_layout_col = 0;
    }
    if(image_grid_layout_size % 5 == 0)
    {
        image_grid_layout_row++;

    }
}

void BoxImage::assign_remove_all_button_content()
{

}

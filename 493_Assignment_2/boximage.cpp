#include "boximage.h"

BoxImage::BoxImage(QWidget *parent, QGridLayout *_image_grid_layout) :
    QWidget(parent)
{
    // Create Stack
    undo_stack = new QUndoStack();

    // Get the Image Grid Layout
    image_grid_layout = new QGridLayout();
    image_grid_layout = _image_grid_layout;

    // Space out the Grid Layout
    for (int i = 0;i < 5; i++)
      {
        image_grid_layout->setColumnMinimumWidth(i,BUTTON_SIZE+10);
        image_grid_layout->setColumnStretch(i,0);
        image_grid_layout->setRowMinimumHeight(i, BUTTON_SIZE+10);
      }
    image_grid_layout->setOriginCorner(Qt::TopLeftCorner);
    image_grid_layout->setSpacing(0);

    // Initialize size variables
    image_grid_layout_row  = 0;
    image_grid_layout_col  = 0;

    // Create QButtonGroup
    image_button_group = new QButtonGroup();

    counter = 0;
}

void BoxImage::assign_add_collection_button_content()
{
    // First open the directory
    open_directory = new QFileDialog();
    QString directory_name = open_directory->getExistingDirectory(this,
                                                                  tr("Select one or more images to open"),
                                                                  "/",
                                                                  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // Check if empty or null
    if(directory_name.isEmpty()  || directory_name.isNull())
    {
        return;
    }

    // Create Directory Structure
    current_directory = new QDir(directory_name);

    current_directory->setNameFilters(QStringList() << "*.jpg"<< "*.bmp"<<  "*.gif" << "*.GIF" << "*.JPG");

    // Create QStringList that houses pic filepath(s)
    directory_list = current_directory->entryList();

    // Get Images to Image Vector List
    for(int i = 2; i < directory_list.size(); i++)
    {
        QString image_file_path = directory_name;
        image_file_path.append("/").append(directory_list.at(i));

        image_pixmap = QPixmap(image_file_path);
        if(image_pixmap.isNull())
        {
            return;
        }
        else
        {
            image_list.append(image_pixmap);
        }
    }

    // Add Images To Grid Layout
    for(int i = 0; i < image_list.size(); i++)
    {
        // Create QToolButton
        image_tool_button = create_new_tool_button(image_list.at(i));

        // Add Label to Grid Layout
        image_grid_layout->addWidget(image_tool_button,
                                     image_grid_layout_row,
                                     image_grid_layout_col,
                                     Qt::AlignTop);

        // Increase Size Parameters
        image_grid_layout_col++;

        // Handle Rows % Columns
        if(image_grid_layout->count() % 5 == 0)
        {
            image_grid_layout_row++;
            image_grid_layout_col = 0;
        }
    }

}

void BoxImage::assign_add_image_button_content(/*int insert_location*/)
{
    // First open the directory
    open_directory = new QFileDialog();
    QString file_name = open_directory->getOpenFileName(this,
                                                        tr("Open Image"),
                                                        QDir::homePath() + QDir::separator() + "*","Images (*.png *.jpg *.jpeg)");


    // Check if empty or null
    if(file_name.isEmpty() || file_name.isNull())
    {
        return;
    }

    // Create QPixmap & QToolButton
    image_pixmap = QPixmap(file_name);
    image_tool_button = create_new_tool_button(image_pixmap);

    // Add Label to Grid Layout
    image_grid_layout->addWidget(image_tool_button,
                                 image_grid_layout_row,
                                 image_grid_layout_col,
                                 Qt::AlignTop);

    // Increase Size Parameters
    image_grid_layout_col++;

    // Handle next row
    if(image_grid_layout->count() % 5 == 0)
    {
        image_grid_layout_row++;
        image_grid_layout_col = 0;

    }
    QVector<QPixmap> image_container;
    image_container.append(image_pixmap);

  //  AddImageCommand *command = new AddImageCommand(image_container,insert_location, this);

 //   undo_stack->push(command);


}

void BoxImage::assign_remove_all_button_content()
{
    // Delete all items in Grid Layout
    for(int i = image_grid_layout->count()-1; i >= 0; i--)
    {
        QLayoutItem *deleted_image = image_grid_layout->itemAt(i);
        delete deleted_image->widget();
    }

    // Reset Size Constraint Variables
    image_grid_layout_col = 0;
    image_grid_layout_row = 0;

    image_list.clear();
}

void BoxImage::assign_not_implemented_msg()
{
    QMessageBox message;
    message.setText("Will be implemented at a later date.");
    message.exec();
}

void BoxImage::assign_quit_action()
{
    QApplication::quit();
}

void BoxImage::assign_copy_action()
{
    QToolButton *selected_image = (QToolButton *) image_button_group->checkedButton();
    if(selected_image == NULL)
    {
        return;
    }
    else
    {
        QApplication::clipboard()->setPixmap(selected_image->icon().pixmap(IMAGE_SIZE, IMAGE_SIZE));
    }
}

void BoxImage::assign_paste_action()
{
    const QMimeData *mime = QApplication::clipboard()->mimeData();

    if(mime->hasImage() == true)
    {
        QVector<QPixmap> paste_image_list;
        QPixmap pasted_image = QApplication::clipboard()->pixmap();
        paste_image_list.append(pasted_image);

        QToolButton *selected_image = (QToolButton *) image_button_group->checkedButton();
        if(selected_image == NULL)
        {
            return;//pasteInsertLocation = imageGrid->count();
        }
        else
        {
            qDebug() << "whatever";
        }
        /*int itemNum = imageGrid->indexOf(selected_image);
        if(itemNum >= 0) pasteInsertLocation = itemNum;

        AddImageCommand *command = new AddImageCommand("paste image",
                                                        ccpPixMap,
                                                        pasteInsertLocation+1,
                                                        this);
       undoStack->push(command);*/

    }

}

void BoxImage::assign_cut_action()
{
    QToolButton *selected_image = (QToolButton *) image_button_group->checkedButton();
    if(selected_image == NULL)
    {
        return;
    }
    else
    {
        qDebug() << "cutting\n";
        QApplication::clipboard()->setPixmap(selected_image->icon().pixmap(IMAGE_SIZE, IMAGE_SIZE));
        // delete the image
    }
}

// Create the QToolButton to be placed on the Grid Layout
QToolButton *BoxImage::create_new_tool_button(QPixmap incoming_pixmap)
{
  QToolButton *button_label = new QToolButton();
  button_label->setIcon(QIcon(incoming_pixmap.scaled(IMAGE_SIZE,
                                                     IMAGE_SIZE,
                                                     Qt::KeepAspectRatio)));
  button_label->setIconSize(QSize(IMAGE_SIZE,IMAGE_SIZE));
  button_label->setMaximumSize(BUTTON_SIZE,BUTTON_SIZE);
  button_label->setMinimumSize(BUTTON_SIZE,BUTTON_SIZE);
  button_label->setCheckable(true);
  image_button_group->addButton(button_label);
  return button_label;
}

void BoxImage::insert_multiple_images(QVector<QPixmap> pixmapList, int insertLoc)
{
  QLayoutItem *item;
  QLayoutItem *item2;
  QIcon icon;
  //int row;
  qDebug() << "inserting ";
  if (pixmapList.count() == 0)
    return;

  // insertLoc is already set to the item *after* the selected label
  QToolButton *newLabel;
  if (insertLoc == counter)
    {
      int loc = 0;

      for (int i=insertLoc;i<insertLoc+pixmapList.count();i++)
    {
      newLabel = create_new_tool_button(pixmapList.at(loc));
      //	  row = (int)(i/5);
      //	  imageGrid->setRowMinimumHeight(row,BUTTON_SIZE+8);
      //	  imageGrid->setRowStretch(row,0);
      image_grid_layout->addWidget(newLabel,(int)(i/5),i%5,Qt::AlignTop);
      loc++;
      qDebug() << "\tinserting pixmap at " << i;
    }
    }
  else // this is ugly, but there are 3 parts to the rearrangement
    {
      int currentEnd = image_grid_layout->count();
      for (int i=0, j=currentEnd;i<pixmapList.count();i++,j++)
    { // add to the end
      item = image_grid_layout->itemAt(j-1);
      icon = ((QToolButton *)item->widget())->icon();
      newLabel = create_new_tool_button(pixmapList.at(i));
      newLabel->setIcon(QIcon(pixmapList.at(i).scaled(IMAGE_SIZE,IMAGE_SIZE,
                             Qt::KeepAspectRatio)));
      newLabel->setIconSize(QSize(IMAGE_SIZE,IMAGE_SIZE));
      image_grid_layout->addWidget(newLabel,(int)(j/5),j%5,Qt::AlignTop);
      //qDebug() << "\tmoving pixmaps from " << insertLoc+1 << " to " << j;
    }
      for (int i=currentEnd;i>insertLoc;i--)
    { // move items down
      item = image_grid_layout->itemAt(i-1);
      icon = ((QToolButton *)item->widget())->icon();
      item2 = image_grid_layout->itemAt(i);
      ((QToolButton *)item2->widget())->setIcon(icon);
      //qDebug() << "\tmoving pixmaps from " << i-1 << " to " << i;
    }
      for (int i=0;i<pixmapList.count();i++)
    { // insert the imageList
      item = image_grid_layout->itemAt(insertLoc+i);
      QWidget *widget = item->widget();
      QToolButton *button = dynamic_cast<QToolButton *>(widget);
      button->setIcon(QIcon(pixmapList.at(i).scaled(IMAGE_SIZE,IMAGE_SIZE,
                             Qt::KeepAspectRatio)));
      //qDebug() << "\tadding pixmap to " << insertLoc+1;
    }
    }
   counter=counter+pixmapList.count();
}

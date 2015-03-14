#include "addimagecommand.h"

AddImageCommand::AddImageCommand(QVector<QPixmap> image_list, int insert_picture_index, BoxImage *box_image_widget)
{
    add_image_cmd_image_list = image_list;
    add_image_cmd_insert_picture_index = insert_picture_index;
    add_image_cmd_box_image_widget = box_image_widget;
}

void AddImageCommand::undo()
{
  int end_location = add_image_cmd_insert_picture_index + add_image_cmd_image_list.size()-1;
 // add_image_cmd_box_image_widge
}

void AddImageCommand::redo()
{
    add_image_cmd_box_image_widget->insert_multiple_images(add_image_cmd_image_list,add_image_cmd_insert_picture_index);
}

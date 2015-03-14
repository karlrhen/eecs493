#ifndef ADDIMAGECOMMAND_H
#define ADDIMAGECOMMAND_H

#include <QUndoCommand>
#include "boximage.h"

class AddImageCommand : public QUndoCommand
{
public:
   explicit AddImageCommand(QVector<QPixmap> image_list = QVector<QPixmap>(),
                            int insert_picture_index = 0,
                            BoxImage* box_image_widget = NULL);
    void undo();
    void redo();

private:
    QVector<QPixmap> add_image_cmd_image_list;
    int               add_image_cmd_insert_picture_index;
    BoxImage         *add_image_cmd_box_image_widget;
};

#endif // ADDIMAGECOMMAND_H

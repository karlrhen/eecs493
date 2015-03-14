#include "deleteimagecommand.h"
#include "boximage.h"


DeleteImageCommand::DeleteImageCommand(QString text, int start, int finish, BoxImage *object)
{
    _start      = start;
    _finish     = finish;
    _boxImage   = object;
    _pixMapList = QVector<QPixmap>();
    text        = "";
}

void DeleteImageCommand::undo()
{
    _boxImage->insertMultipleImages(_pixMapList,_start);
}

void DeleteImageCommand::redo()
{
    _boxImage->deleteImages(_start,_finish);
}

void DeleteImageCommand::setPixmapList(QVector<QPixmap> pixMapList)
{
    _pixMapList = pixMapList;
}

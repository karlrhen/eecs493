#include "deleteallcommand.h"
#include "boximage.h"
#include <QDebug>

DeleteAllCommand::DeleteAllCommand(QString text, int start, int finish, BoxImage* object )
{
    _start      = start;
    _finish     = finish;
    _boxImage   = object;
    text        = "";
}

void DeleteAllCommand::undo()
{
    _boxImage->insertMultipleImages(_pixMapList,_start);
}

void DeleteAllCommand::redo()
{
    _boxImage->deleteImages(_start,_finish);
}

void DeleteAllCommand::setPixmapList(QVector<QPixmap> pixMapList)
{
    _pixMapList = pixMapList;
}

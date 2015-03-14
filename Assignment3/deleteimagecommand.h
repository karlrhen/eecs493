#ifndef DELETEIMAGECOMMAND_H
#define DELETEIMAGECOMMAND_H

#include <QUndoCommand>
#include <QPixmap>
#include "boximage.h"

class DeleteImageCommand : public QUndoCommand
{

public:
    DeleteImageCommand(QString text = "", int start = 0, int end = 0, BoxImage *object = 0);
    void undo();
    void redo();
    void setPixmapList(QVector<QPixmap> pixMapList);


private:
    int _start;
    int _finish;
    QVector<QPixmap> _pixMapList;
    BoxImage* _boxImage;
};

#endif // DELETEIMAGECOMMAND_H

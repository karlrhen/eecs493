#ifndef ADDCOLLECTIONCOMMAND_H
#define ADDCOLLECTIONCOMMAND_H

#include <QUndoCommand>
#include <QPixmap>
#include "boximage.h"
class AddCollectionCommand : public QUndoCommand
{

public:
    AddCollectionCommand(QString text = "",
                         QVector<QPixmap> imageVector = QVector<QPixmap>(),
                         int insertLocation = 0,
                         BoxImage* object   = 0);
    void undo();
    void redo();

private:
    int _insertLocation;
    QVector<QPixmap> _imageVector;
    BoxImage *_boxImage;
};

#endif // ADDCOLLECTIONCOMMAND_H



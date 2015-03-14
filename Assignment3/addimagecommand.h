#ifndef ADDIMAGECOMMAND_H
#define ADDIMAGECOMMAND_H

#include <QUndoCommand>
#include "boximage.h"
class AddImageCommand : public QUndoCommand
{

public:
    explicit AddImageCommand(QString text = "",
                             QVector<QPixmap> imageVector = QVector<QPixmap>(),
                             int insertLocation = 0,
                             BoxImage* object = NULL);
    void undo();
    void redo();

private:
    BoxImage *_boxImage;
    QVector<QPixmap> _imageVector;
    int _insertLocation;

};

#endif // ADDIMAGECOMMAND_H

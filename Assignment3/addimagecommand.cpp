#include "addimagecommand.h"


AddImageCommand::AddImageCommand(QString text, QVector<QPixmap> imageVector, int insertLocation, BoxImage* object)
{
    _boxImage       = object;
    _imageVector    = imageVector;
    _insertLocation = insertLocation;
    text            = "";
}

void AddImageCommand::undo()
{
    int _endLocation = _insertLocation + _imageVector.size()-1;
    _boxImage->deleteImages(_insertLocation, _endLocation);
}

void AddImageCommand::redo()
{
    _boxImage->insertMultipleImages(_imageVector, _insertLocation);
}

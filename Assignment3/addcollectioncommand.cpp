#include "addcollectioncommand.h"

AddCollectionCommand::AddCollectionCommand(QString purpose,
                                           QVector<QPixmap> imageVector,
                                           int insertLocation,
                                           BoxImage *object)
{
    _insertLocation = insertLocation;
    _imageVector    = imageVector;
    _boxImage       = object;
    purpose = "";

}

void AddCollectionCommand::undo()
{
    _boxImage->deleteImages(_insertLocation,_insertLocation + (_imageVector.size() - _insertLocation));
}

void AddCollectionCommand::redo()
{
    _boxImage->insertMultipleImages(_imageVector, _insertLocation);
}

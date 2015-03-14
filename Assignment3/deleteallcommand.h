#ifndef DELETEALLCOMMAND_H
#define DELETEALLCOMMAND_H

#include <QUndoCommand>
#include <QObject>
#include "boximage.h"

class DeleteAllCommand : public QUndoCommand
{

public:
    DeleteAllCommand(QString text     = "",
                     int start        = 0,
                     int finish       = 0,
                     BoxImage* object = 0);
    void undo();
    void redo();
    void setPixmapList(QVector<QPixmap> pixMapList);
public slots:

private:
    QVector<QPixmap> _pixMapList;
    int _start;
    int _finish;
    BoxImage* _boxImage;

};

#endif // DELETEALLCOMMAND_H


/*DeleteAllCommand *command = new DeleteAllCommand("delete all",
                         0, counter-1, this);*/

#ifndef BOXIMAGE_H
#define BOXIMAGE_H

#include <QtWidgets>

class BoxImage : public QFrame
{
  Q_OBJECT

 public:
  explicit BoxImage(QUndoStack *undoStack_incoming, QWidget *parent = 0);
  void insertMultipleImages(QVector<QPixmap> pixmapVector, int loc);
  void deleteImages(int begin, int end);

 protected:
  int nrows;
  int counter;
  QGridLayout *imageGrid;
  QButtonGroup *buttonGroup;
    QUndoStack *undoStack;
  void appendImage(QString fileName);
  void appendImage(QPixmap pixmap_incoming);
  QToolButton *newToolButton(QPixmap pixmap_incoming);
  void insertImageCallback(int insertLoc);
  //void insertImage(QString filename, int loc);


public slots:
  void addCollectionCallback();
  void addImageCallback();
  void deleteAllCallback();
  void deleteImageCallback();
  void insertImageCallback();
  void insertMultipleImagesCallback(int insertLoc);
};

#endif // BOXIMAGE_H

#ifndef BOXIMAGE_H
#define BOXIMAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QButtonGroup>
#include <QFrame>
#include <QToolButton>
#include <QMimeData>

class QUndoStack;
class BoxImage : public QFrame
{
  Q_OBJECT

 public:
  explicit BoxImage(QUndoStack *undoStack_incoming, QClipboard *clipBoardIn, QAction *addCollectionIn, QAction *addImageIn, QWidget *parent = 0);
  void insertMultipleImages(QVector<QPixmap> pixmapVector, int loc);
  void deleteImages(int begin, int end);
  QButtonGroup *buttonGroup;
  QGridLayout *imageGrid;


 protected:
  int nrows;
  int counter;
  QUndoStack *undoStack;
  QClipboard *clipBoard;
  QAction *addCollectionAction;
  QAction *addImageAction;
  void appendImage(QString fileName);
  QStringList imageTypeList;
  void appendImage(QPixmap pixmap_incoming);
  QToolButton *newToolButton(QPixmap pixmap_incoming);
  void insertImageCallback(int insertLoc);
  //MainWindow* mainWindow;
  QVector<QPixmap> flickrVec;
  int flickrCounter;
  //void insertImage(QString filename, int loc);


public slots:
  void addCollectionCallback();
  void addImageCallback();
  void deleteAllCallback();
  void deleteImageCallback();
  void insertImageCallback();
  void insertMultipleImagesCallback(int insertLoc);
  void cutCallback();
  void pasteCallback();
  void copyCallback();
  void quit();
  void executeFlickr();
  void addFlickrFailed();
  void addFlickrReady();
  void imageCollectorPixmap(QPixmap pixmap);

  void playCallback();

private:
   bool pasteActivated;
   bool cutActivated;
   int  pasteInsertLocation;
};

#endif // BOXIMAGE_H

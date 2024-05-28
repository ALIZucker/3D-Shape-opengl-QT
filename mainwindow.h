#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QTimer>
#include <GL/GLU.h>


class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void resizeGL(int w , int h);
 protected:
    virtual void initializeGL();

    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent * event);

 public slots:
    void UpdateAnim();
private:
    QOpenGLContext *context;
    QOpenGLFunctions *openFunc;
    float rotation;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)

{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);

    context=new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openFunc=context->functions();
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateAnim()));
    timer->start(100);
    rotation=0;


}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    glEnable(GL_DEPTH_TEST);

            resizeGL(this->width(),this->height());
}

void MainWindow::resizeGL(int w, int h)
{
   // glMatrixMode(GL_PROJECTION);
   // glLoadIdentity();

   // glViewport(0,0,w,h);
    //qreal aspect=qreal(w)/qreal(h);
//    glOrtho(-1*aspect,1*aspect,-1,1,1,-1);

    glViewport(0,0,w,h);
    qreal aspec=qreal(w)/qreal(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75,aspec,0.1,400000000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}


void MainWindow::paintGL()
{

glClearColor(0.39f,0.58f,0.93f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      glTranslatef(0.0,0.0,-3.0);
      glRotatef(rotation,1.0,1.0,1.0);

      //front
      glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,0.0);
      glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
          glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,-0.5,-0.5);
      glEnd();

      //back
      glBegin(GL_POLYGON);
      glColor3f(0.0,1.0,0.0);
      glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,0.5);
          glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
      glEnd();

      //right
      glBegin(GL_POLYGON);
      glColor3f(1.0,0.0,1.0);
      glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
          glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
      glEnd();

      //left
      glBegin(GL_POLYGON);
      glColor3f(1.0,1.0,0.0);
      glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
          glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,-0.5,-0.5);
      glEnd();

      //top
      glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,1.0);
      glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
          glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,0.5);
      glEnd();

      //botm
      glBegin(GL_POLYGON);
      glColor3f(1.0,0.0,0.0);
      glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,0.5);
          glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);
      glEnd();

/*
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.5f,-0.5f);
        glColor3f(0.0f,1.0f,0.0f);
      glVertex2f(0.5f,-0.5f);
          glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.5f,0.5f);
            glColor3f(1.0f,1.0f,0.0f);
          glVertex2f(-0.5f,0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-0.4f,-0.4f);
  glColor3f(0.5f,0.2f,0.5f);
    glVertex2f(0.8f,-0.1f);
  glColor3f(0.5f,0.5f,0.8f);
    glVertex2f(-0.1f,-0.8f);
    glEnd();
*/
    glFlush();




}

void MainWindow::resizeEvent(QResizeEvent *event)
{

        resizeGL(this->width(),this->height());
        this->update();


}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();

}

void MainWindow::UpdateAnim()
{
    rotation+=10;
    this->update();
}


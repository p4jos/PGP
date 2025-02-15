#include "main_window.h"
#include "ogl.h"

#include <QApplication>
#include <QSurfaceFormat>



int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  // Nastavenie defaultneho OpenGL formatu (core profil verzie 3.3)
  QSurfaceFormat format;
  format.setVersion(3, 3);
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setOption(QSurfaceFormat::DebugContext);

  QSurfaceFormat::setDefaultFormat(format);

  MainWindow w;
  w.show();

  return app.exec();
}

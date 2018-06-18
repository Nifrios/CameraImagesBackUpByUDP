///
/// \file main.cpp
/// \brief Main file of the program
/// \author Florian Roussel
/// \date 2018-06-06
///

// C++ Standard
// Qt librairies
#include <QCoreApplication>
// Modules
// App
#include "CAMERA_ClassCameraDataManager.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   // Main class of camera data management
   CLASS_CAMERA_DATA_MANAGER CameraDataManager(12345);
   // Launch initialization
   CameraDataManager.Start();

   return a.exec();
}

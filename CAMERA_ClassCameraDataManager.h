///
/// \file CAMERA_ClassCameraDataManager.h
/// \brief CLASS_CAMERA_DATA_MANAGER class
/// \author Florian Roussel
/// \date 2018-06-06
///

#ifndef CAMERA_CLASSCAMERADATAMANAGER_H
#define CAMERA_CLASSCAMERADATAMANAGER_H

// C++ Standard
// Qt librairies
#include <QObject>
// Modules
#include "COMMON_TypeDefs.h"

///
/// \class CLASS_CAMERA_DATA_MANAGER
/// \brief CLASS_CAMERA_DATA_MANAGER class
///
class CLASS_CAMERA_DATA_MANAGER : public QObject
{
      Q_OBJECT

   public:

      /*--------------------------- Public types ---------------------------*/

      /*------------------------- Public constants ------------------------*/

      /*---------------------- Constructor / Destructor ---------------------*/

      ///
      /// \fn CLASS_CAMERA_DATA_MANAGER(QObject *parent)
      /// \brief CLASS_CAMERA_DATA_MANAGER constructor
      ///
      /// \param[in] parent : Objet parent
      ///
      CLASS_CAMERA_DATA_MANAGER(QObject *parent = nullptr);

      ///
      /// \fn ~CLASS_CAMERA_DATA_MANAGER()
      /// \brief CLASS_CAMERA_DATA_MANAGER destructor
      ///
      ~CLASS_CAMERA_DATA_MANAGER();

      /*------------------------------ Getter -----------------------------*/

      /*------------------------------ Setter ------------------------------*/

      /*-------------------------- Public methods  -------------------------*/

      ///
      /// \fn Start
      /// \brief Start class initialisation
      ///
      void Start(void);

      /*--------------------------- Public signals -------------------------*/

   signals:

      /*---------------------------- Public slots --------------------------*/

   public slots:

      /*----------------------------- Private types ----------------------------*/

      /*--------------------------- Private methods --------------------------*/

   protected:

   private:

      /*------------------------------ Variables ------------------------------*/

   protected:

   private:

};

#endif // CAMERA_CLASSCAMERADATAMANAGER_H

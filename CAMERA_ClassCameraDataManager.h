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
// App
#include "CAMERA_ClassCameraImage.h"

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

      ///
      /// \fn SLOT_NewDataReceived
      /// \brief Receive new raw data from communication
      /// \param[in] rawData : Raw data
      ///
      void SLOT_NewDataReceived(const QByteArray& rawData);

      /*----------------------------- Private types ----------------------------*/

      /*--------------------------- Private methods --------------------------*/

   protected:

   private:

      /*------------------------------ Variables ------------------------------*/

   protected:

   private:

      QMap<Word, CLASS_CAMERA_IMAGE*> f_CurrentImage;    ///< Current image depends on raw buffer

};

#endif // CAMERA_CLASSCAMERADATAMANAGER_H

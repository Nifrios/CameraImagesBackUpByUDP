///
/// \file CAMERA_ClassCameraImage.h
/// \brief CLASS_CAMERA_IMAGE class
/// \author Florian Roussel
/// \date 2018-06-06
///

#ifndef CAMERA_CLASSCAMERAIMAGE_H
#define CAMERA_CLASSCAMERAIMAGE_H

// C++ Standard
// Qt librairies
#include <QMap>
#include <QObject>
// Modules
#include "COMMON_TypeDefs.h"

///
/// \class CLASS_CAMERA_IMAGE
/// \brief CLASS_CAMERA_IMAGE class
///
class CLASS_CAMERA_IMAGE : public QObject
{
      Q_OBJECT

   public:

      /*--------------------------- Public types ---------------------------*/

      /*------------------------- Public constants ------------------------*/

      /*---------------------- Constructor / Destructor ---------------------*/

      ///
      /// \fn CLASS_CAMERA_IMAGE(QObject *parent)
      /// \brief CLASS_CAMERA_IMAGE constructor
      ///
      /// \param[in] imageID : Image identifier
      /// \param[in] verticalResolution : Vertical resolution
      /// \param[in] horizontalResolutation : Horizontal resolution
      /// \param[in] parent : Objet parent
      ///
      CLASS_CAMERA_IMAGE(Word imageID, Word verticalResolution, Word horizontalResolutation, QObject *parent = nullptr);

      ///
      /// \fn ~CLASS_CAMERA_IMAGE()
      /// \brief CLASS_CAMERA_IMAGE destructor
      ///
      ~CLASS_CAMERA_IMAGE();

      /*------------------------------ Getter -----------------------------*/

      ///
      /// \fn GetImageID
      /// \brief Get image identifier
      /// \return Word \e Image identifier
      ///
      Word GetImageID(void) const;

      ///
      /// \fn GetVerticalResolution
      /// \brief Get vertical resolution
      /// \return Word \e Vertical resolution
      ///
      Word GetVerticalResolution(void) const;

      ///
      /// \fn GetHorizontalResolution
      /// \brief Get horizontal resolution
      /// \return Word \e horizontal resolution
      ///
      Word GetHorizontalResolution(void) const;

      ///
      /// \fn GetPixels
      /// \brief Get data per line
      /// \return QMap<Word, QByteArray> \e Data per line
      ///
      const QMap<Word, QByteArray>& GetPixels(void) const;

      /*------------------------------ Setter ------------------------------*/

      /*-------------------------- Public methods  -------------------------*/

      ///
      /// \fn AppendPixelsData
      /// \brief Append pixels data in image
      /// \param[in] lineNumber : Line number
      /// \param[in] pixels : Pixels
      ///
      void AppendPixelsData(const Word lineNumber, const QByteArray& pixels);

      ///
      /// \fn ImageIsReadyToExport
      /// \brief Indicate if image contains all wanted data
      /// \return Bool \e True if image contains all wanted data
      ///
      Bool ImageIsReadyToExport(void);

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

      Word f_ImageId;                     /// Image identifier
      Word f_VerticalResolution;          /// Vertical resolution
      Word f_HorizontalResolution;        /// Horizontal resolution
      QMap<Word, QByteArray> f_Pixels;    /// Data per line

};

#endif // CAMERA_CLASSCAMERAIMAGE_H

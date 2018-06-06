///
/// \file CAMERA_ClassCameraProtocolData.h
/// \brief CLASS_CAMERA_PROTOCOL_DATA class
/// \author Florian Roussel
/// \date 2018-06-06
///

#ifndef CAMERA_CLASSCAMERAPROTOCOLDATA_H
#define CAMERA_CLASSCAMERAPROTOCOLDATA_H

// C++ Standard
// Qt librairies
#include <QObject>
// Modules
#include "COMMON_TypeDefs.h"

///
/// \class CLASS_CAMERA_PROTOCOL_DATA
/// \brief CLASS_CAMERA_PROTOCOL_DATA class
///
class CLASS_CAMERA_PROTOCOL_DATA : public QObject
{
      Q_OBJECT

   public:

      /*--------------------------- Public types ---------------------------*/

      /*------------------------- Public constants ------------------------*/

      /*---------------------- Constructor / Destructor ---------------------*/

      ///
      /// \fn CLASS_CAMERA_PROTOCOL_DATA(QObject *parent)
      /// \brief CLASS_CAMERA_PROTOCOL_DATA constructor
      ///
      /// \param[in] imageID : Image identifier
      /// \param[in] lineNumber : Line number
      /// \param[in] verticalResolution : Vertical resolution
      /// \param[in] horizontalResolutation : Horizontal resolution
      /// \param[in] parent : Parent object
      ///
      CLASS_CAMERA_PROTOCOL_DATA(Word imageID = 0, Word lineNumber = 0, Word verticalResolution = 0, Word horizontalResolutation = 0, QObject *parent = nullptr);

      ///
      /// \fn ~CLASS_CAMERA_PROTOCOL_DATA()
      /// \brief CLASS_CAMERA_PROTOCOL_DATA destructor
      ///
      ~CLASS_CAMERA_PROTOCOL_DATA();

      /*------------------------------ Getter -----------------------------*/

      ///
      /// \fn GetImageID
      /// \brief Get image identifier
      /// \return Word \e Image identifier
      ///
      Word GetImageID(void) const;

      ///
      /// \fn GetLineNumber
      /// \brief Get line number
      /// \return Word \e Line number
      ///
      Word GetLineNumber(void) const;

      ///
      /// \fn GetVerticalIdentifier
      /// \brief Get vertical identifier
      /// \return Word \e Vertical identifier
      ///
      Word GetVerticalIdentifier(void) const;

      ///
      /// \fn GetHorizontalIdentifier
      /// \brief Get horizontal identifier
      /// \return Word \e horizontal identifier
      ///
      Word GetHorizontalIdentifier(void) const;

      /*------------------------------ Setter ------------------------------*/

      ///
      /// \fn SetImageID
      /// \brief Set image identifier
      /// \param[in] imageID : image identifier
      ///
      void SetImageID(const Word imageID);

      ///
      /// \fn SetLineNumber
      /// \brief Set line number
      /// \param[in] lineNumber : line number
      ///
      void SetLineNumber(const Word lineNumber);

      ///
      /// \fn SetVerticalResolution
      /// \brief Set vertical resolution
      /// \param[in] verticalResolution : vertical resolution
      ///
      void SetVerticalResolution(const Word verticalResolution);

      ///
      /// \fn SetHorizontalResolution
      /// \brief Set horizontal resolution
      /// \param[in] horizontalResolution : horizontal resolution
      ///
      void SetHorizontalResolution(const Word horizontalResolution);

      /*-------------------------- Public methods  -------------------------*/

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

      Word f_ImageId;               /// Image identifier
      Word f_LineNumber;            /// Line number
      Word f_VerticalResolution;    /// Vertical resolution
      Word f_HorizontalResolution;  /// Horizontal resolution

};

#endif // CAMERA_CLASSCAMERAPROTOCOLDATA_H

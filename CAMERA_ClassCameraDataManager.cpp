///
/// \file CAMERA_ClassCameraDataManager.cpp
/// \brief Classe CLASS_CAMERA_DATA_MANAGER
/// \author ANALOG WAY - FRO
/// \date 2018-06-06
///
/// CLASS_CAMERA_DATA_MANAGER functions
///

// C++ Standard
// Qt librairies
#include <QDebug>
#include <QStringBuilder>
// Modules
#include "CAMERA_ClassCameraDataManager.h"
// App
#include "CAMERA_ClassCameraProtocolDecode.h"

/******************************** DEFINITIONS ********************************/

/*----------------------------- Public types -----------------------------*/
/*--------------------------- Public constants --------------------------*/
/*--------------------------- Public variables ---------------------------*/
/*------------------------------- Private types ------------------------------*/
/*---------------------------- Private constants ---------------------------*/
/*---------------------------- Private variables ----------------------------*/

/**************************** DEFINITIONS ENDING ****************************/

/******************************************************************************
 *                             Private functions                              *
 *****************************************************************************/

/******************************************************************************
 *                          Constructor / Destructor                          *
 *****************************************************************************/

///
/// \fn CLASS_CAMERA_DATA_MANAGER(QObject *parent)
/// \brief CLASS_CAMERA_DATA_MANAGER constructor
///
/// \param[in] parent : Objet parent
///
CLASS_CAMERA_DATA_MANAGER::CLASS_CAMERA_DATA_MANAGER(QObject *parent):
   QObject(parent)
{

}

///
/// \fn ~CLASS_CAMERA_DATA_MANAGER()
/// \brief CLASS_CAMERA_DATA_MANAGER destructor
///
CLASS_CAMERA_DATA_MANAGER::~CLASS_CAMERA_DATA_MANAGER()
{
}

/******************************************************************************
 *                                 Getter                                     *
 *****************************************************************************/

/******************************************************************************
 *                                  Setter                                    *
 *****************************************************************************/

/******************************************************************************
 *                             Public methods                                 *
 *****************************************************************************/

///
/// \fn Start
/// \brief Start class initialisation
///
void CLASS_CAMERA_DATA_MANAGER::Start(void)
{
   QByteArray FakeRawData;

   // Fake image identifier
   FakeRawData.insert(0, 0x2A);
   FakeRawData.insert(1, '\x00');

   // Fake line number
   FakeRawData.insert(2, 0x0B);
   FakeRawData.insert(3, '\x00');

   // Fake vertical resolution
   FakeRawData.insert(4, 0xF0);
   FakeRawData.insert(5, '\x00');

   // Fake horizontal resolution
//   FakeRawData.insert(6, 0x40);
//   FakeRawData.insert(7, 0x01);
   FakeRawData.insert(6, 0x01);
   FakeRawData.insert(7, '\x00');

   // Fake one byte data
   FakeRawData.insert(8, 0x06);

   // Call new data received
   this->SLOT_NewDataReceived(FakeRawData);
}

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

///
/// \fn SLOT_NewDataReceived
/// \brief Receive new raw data from communication
/// \param[in] rawData : Raw data
///
void CLASS_CAMERA_DATA_MANAGER::SLOT_NewDataReceived(const QByteArray& rawData)
{
   // Contains decoded data from raw data received
   CLASS_CAMERA_PROTOCOL_DATA ProtocolDataDecoded;

   // Status of decoding data
   Bool DecodeDataStatus(CLASS_CAMERA_PROTOCOL_DECODE::Decode(rawData, &ProtocolDataDecoded));

   // If decoding status is true, we append/create image data
   if (DecodeDataStatus == true)
   {
      const Word ImageId(ProtocolDataDecoded.GetImageID());

      // If we haven't this image, we create it
      if (f_CurrentImage.contains(ImageId) == false)
         f_CurrentImage.insert(ImageId, new CLASS_CAMERA_IMAGE(ImageId, ProtocolDataDecoded.GetVerticalResolution(), ProtocolDataDecoded.GetHorizontalResolution()));

      // Get current image object
      CLASS_CAMERA_IMAGE* CurrentImage(f_CurrentImage.value(ImageId));

      if (CurrentImage != nullptr)
      {

      }
      else
      {
         qDebug() << "Cannot get image object for image identifier: " % QString::number(ImageId);
      }
   }
   else
   {
      qDebug() << "Error decoding data frame: " % rawData;
   }
}

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

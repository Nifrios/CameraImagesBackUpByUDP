///
/// \file CAMERA_ClassCameraProtocolDecode.cpp
/// \brief Classe CLASS_CAMERA_PROTOCOL_DECODE
/// \author Florian Roussel
/// \date 2018-06-06
///
/// CLASS_CAMERA_PROTOCOL_DECODE functions
///

// C++ Standard
// Qt librairies
#include <QDebug>
#include <QStringBuilder>
// Modules
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
/// \fn CLASS_CAMERA_PROTOCOL_DECODE(QObject *parent)
/// \brief CLASS_CAMERA_PROTOCOL_DECODE constructor
///
/// \param[in] parent : Parent object
///
CLASS_CAMERA_PROTOCOL_DECODE::CLASS_CAMERA_PROTOCOL_DECODE(QObject *parent):
   QObject(parent)
{

}

///
/// \fn ~CLASS_CAMERA_PROTOCOL_DECODE()
/// \brief CLASS_CAMERA_PROTOCOL_DECODE destructor
///
CLASS_CAMERA_PROTOCOL_DECODE::~CLASS_CAMERA_PROTOCOL_DECODE()
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
/// \fn Decode
/// \brief Decode raw data
/// \param[in] rawData : Raw data from communication
/// \param[in] protocolDataDecoded
/// \return Bool \e If raw data has been decoded into protocolDataDecoded
///
Bool CLASS_CAMERA_PROTOCOL_DECODE::Decode(const QByteArray& rawData, CLASS_CAMERA_PROTOCOL_DATA* protocolDataDecoded)
{
   // Raw data must contains 8 header data
   if (rawData.length() < 8)
      return false;

   // Copy raw data for manipulation
   QByteArray RawData(rawData);

   /*********************************
    * DECODE DATA
    * *******************************/
   // Image ID
   Word ImageId(0);
   // Extract and set data
   memcpy(&ImageId, RawData.left(sizeof(Word)), sizeof(Word));
   protocolDataDecoded->SetImageID(ImageId);
   // Remove data traited
   RawData.remove(0, sizeof(Word));

   // Line number
   Word LineNumber(0);
   // Extract and set data
   memcpy(&LineNumber, RawData.left(sizeof(Word)), sizeof(Word));
   protocolDataDecoded->SetLineNumber(LineNumber);
   // Remove data traited
   RawData.remove(0, sizeof(Word));

   // Vertical resolution
   Word VerticalResolution(0);
   // Extract and set data
   memcpy(&VerticalResolution, RawData.left(sizeof(Word)), sizeof(Word));
   protocolDataDecoded->SetVerticalResolution(VerticalResolution);
   // Remove data traited
   RawData.remove(0, sizeof(Word));

   // Horizontal resolution
   Word HorizontalResolution(0);
   // Extract and set data
   memcpy(&HorizontalResolution, RawData.left(sizeof(Word)), sizeof(Word));
   protocolDataDecoded->SetHorizontalResolution(HorizontalResolution);
   // Remove data traited
   RawData.remove(0, sizeof(Word));

   // Pixels
   // Check if pixels length correspond to horizontal resolution value
   if (RawData.length() != protocolDataDecoded->GetHorizontalResolution())
   {
      qDebug() << "Pixels data (" % QString::number(RawData.length()) % ") does not correspond to horizontal resolution value \"" %
                  QString::number(protocolDataDecoded->GetHorizontalResolution()) % "\"";
      return false;
   }
   protocolDataDecoded->SetPixels(RawData);

   return true;
}

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

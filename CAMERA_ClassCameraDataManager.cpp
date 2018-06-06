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
}

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

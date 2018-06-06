///
/// \file CAMERA_ClassCameraProtocolDecode.cpp
/// \brief Classe CLASS_CAMERA_PROTOCOL_DECODE
/// \author ANALOG WAY - FRO
/// \date 2018-06-06
///
/// CLASS_CAMERA_PROTOCOL_DECODE functions
///

// C++ Standard
// Qt librairies
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

}

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

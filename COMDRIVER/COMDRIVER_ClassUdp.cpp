///
/// \file COMDRIVER_ClassUdp.cpp
/// \brief Classe CLASS_UDP
/// \author ANALOG WAY - FRO
/// \date 2018-06-06
///
/// CLASS_UDP functions
///

// C++ Standard
// Qt librairies
// Modules
#include "COMDRIVER_ClassUdp.h"

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
/// \fn CLASS_UDP(QObject *parent)
/// \brief CLASS_UDP constructor
///
/// \param[in] localAddress : Local IP
/// \param[in] portNumber : Local port
/// \param[in] remoteAddress : Remote IP
/// \param[in] remotePort : Remote port
/// \param[in] parent : Objet parent
///
CLASS_UDP::CLASS_UDP(const QHostAddress& localAddress, const Word localPort, const QHostAddress& remoteAddress, const Word remotePort, QObject *parent):
   QObject(parent),
   f_Socket(parent),
   f_LocalAddress(localAddress),
   f_LocalPort(localPort),
   f_RemoteAddress(remoteAddress),
   f_RemotePort(remotePort)
{

}

///
/// \fn ~CLASS_UDP()
/// \brief CLASS_UDP destructor
///
CLASS_UDP::~CLASS_UDP()
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

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

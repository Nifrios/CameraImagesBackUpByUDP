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
   // Connect data reception
   QObject::connect(&f_Socket, &QUdpSocket::readyRead, this, &CLASS_UDP::ReceiveDataFromPort);
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

///
/// \fn ReceiveDataFromPort
/// \brief Receive data from port
///
void CLASS_UDP::ReceiveDataFromPort(void)
{
   QHostAddress RemoteAddress(QHostAddress::Null);
   Word RemotePort(0);
   QByteArray Message;

   // No data, we stop
   if (f_Socket.pendingDatagramSize() == 0)
      return;

   Message.resize(f_Socket.pendingDatagramSize());

   // Read message
   f_Socket.readDatagram(Message.data(), Message.size() , &RemoteAddress, &RemotePort);

   // No data, we stop
   if (Message.isEmpty() == true)
      return;

   // Emit new data available
   emit this->SIGNAL_NewDataAvailable(Message);
}

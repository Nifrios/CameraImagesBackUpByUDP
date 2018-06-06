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
#include <QDebug>
#include <QStringBuilder>
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
/// \param[in] parent : Objet parent
///
CLASS_UDP::CLASS_UDP(const QHostAddress& localAddress, const Word localPort, QObject *parent):
   QObject(parent),
   f_Socket(parent),
   f_LocalAddress(localAddress),
   f_LocalPort(localPort)
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
   // Close connection if opened
   if (f_Socket.state() == QAbstractSocket::ConnectedState)
      this->Close();
}

/******************************************************************************
 *                                 Getter                                     *
 *****************************************************************************/

///
/// \fn Open
/// \brief Open connection
/// \return \e Bool : true if opened
///
Bool CLASS_UDP::Open(void)
{
   // Démarrage de la connexion avec le serveur
   if (f_Socket.bind(f_LocalAddress, f_LocalPort) == true)
   {
      return true;
   }
   else
   {
      qDebug() << "Failed to bind with address: " % f_LocalAddress.toString() % " with port: " % QString::number(f_LocalPort);
      return false;
   }
}

///
/// \fn Close
/// \brief Close connection
///
void CLASS_UDP::Close(void)
{
   f_Socket.close();
}

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

///
/// \file COMDRIVER_ClassUdp.h
/// \brief CLASS_UDP class
/// \author Florian Roussel
/// \date 2018-06-06
///

#ifndef COMDRIVER_CLASSUDP_H
#define COMDRIVER_CLASSUDP_H

// C++ Standard
// Qt librairies
#include <QHostAddress>
#include <QObject>
#include <QUdpSocket>
// Modules
#include "COMMON_TypeDefs.h"

///
/// \class CLASS_UDP
/// \brief CLASS_UDP class
///
class CLASS_UDP : public QObject
{
      Q_OBJECT

   public:

      /*--------------------------- Public types ---------------------------*/

      /*------------------------- Public constants ------------------------*/

      /*---------------------- Constructor / Destructor ---------------------*/

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
      CLASS_UDP(const QHostAddress& localAddress = QHostAddress::LocalHost, const Word localPort = 12345, const QHostAddress& remoteAddress = QHostAddress::LocalHost, const Word remotePort = 123456, QObject *parent = nullptr);

      ///
      /// \fn ~CLASS_UDP()
      /// \brief CLASS_UDP destructor
      ///
      ~CLASS_UDP();

      /*------------------------------ Getter -----------------------------*/

      /*------------------------------ Setter ------------------------------*/

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

      QUdpSocket f_Socket;                       ///< Udp socket
      QHostAddress f_LocalAddress;               ///< Local IP
      Word f_LocalPort;                          ///< Local port
      QHostAddress f_RemoteAddress;              ///< Remote IP
      Word f_RemotePort;                         ///< Remote port

};

#endif // COMDRIVER_CLASSUDP_H

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
      CLASS_UDP(const QHostAddress& localAddress = QHostAddress::LocalHost, const Word localPort = 12345, const QHostAddress& remoteAddress = QHostAddress::LocalHost, Word remotePort = 123456, QObject *parent = nullptr);

      ///
      /// \fn ~CLASS_UDP()
      /// \brief CLASS_UDP destructor
      ///
      ~CLASS_UDP();

      /*------------------------------ Getter -----------------------------*/

      /*------------------------------ Setter ------------------------------*/

      /*-------------------------- Public methods  -------------------------*/

      ///
      /// \fn Open
      /// \brief Open connection
      /// \return \e Bool : true if opened
      ///
      Bool Open(void);

      ///
      /// \fn Close
      /// \brief Close connection
      ///
      void Close(void);

      /*--------------------------- Public signals -------------------------*/

   signals:

      ///
      /// \fn SIGNAL_NewDataAvailable
      /// \brief New data available
      /// \param[in] data : rawData
      ///
      void SIGNAL_NewDataAvailable(const QByteArray& rawData);

      /*---------------------------- Public slots --------------------------*/

   public slots:

      /*----------------------------- Private types ----------------------------*/

      /*--------------------------- Private methods --------------------------*/

   protected:

   private:

      ///
      /// \fn ReceiveDataFromPort
      /// \brief Receive data from port
      ///
      void ReceiveDataFromPort(void);

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

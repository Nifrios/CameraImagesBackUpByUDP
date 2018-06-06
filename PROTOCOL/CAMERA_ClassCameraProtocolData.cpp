///
/// \file CAMERA_ClassCameraProtocolData.cpp
/// \brief Classe CLASS_CAMERA_PROTOCOL_DATA
/// \author ANALOG WAY - FRO
/// \date 2018-06-06
///
/// CLASS_CAMERA_PROTOCOL_DATA functions
///

// C++ Standard
// Qt librairies
// Modules
#include "CAMERA_ClassCameraProtocolData.h"

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
/// \fn CLASS_CAMERA_PROTOCOL_DATA(QObject *parent)
/// \brief CLASS_CAMERA_PROTOCOL_DATA constructor
///
/// \param[in] imageID : Image identifier
/// \param[in] lineNumber : Line number
/// \param[in] verticalResolution : Vertical resolution
/// \param[in] horizontalResolutation : Horizontal resolution
/// \param[in] parent : Parent object
///
CLASS_CAMERA_PROTOCOL_DATA::CLASS_CAMERA_PROTOCOL_DATA(Word imageID, Word lineNumber, Word verticalResolution, Word horizontalResolutation, QObject *parent):
   QObject(parent),
   f_ImageId(imageID),
   f_LineNumber(lineNumber),
   f_VerticalResolution(verticalResolution),
   f_HorizontalResolution(horizontalResolutation)
{

}

///
/// \fn ~CLASS_CAMERA_PROTOCOL_DATA()
/// \brief CLASS_CAMERA_PROTOCOL_DATA destructor
///
CLASS_CAMERA_PROTOCOL_DATA::~CLASS_CAMERA_PROTOCOL_DATA()
{
}

/******************************************************************************
 *                                 Getter                                     *
 *****************************************************************************/

///
/// \fn GetImageID
/// \brief Get image identifier
/// \return Word \e Image identifier
///
Word CLASS_CAMERA_PROTOCOL_DATA::GetImageID(void) const
{
   return f_ImageId;
}

///
/// \fn GetLineNumber
/// \brief Get line number
/// \return Word \e Line number
///
Word CLASS_CAMERA_PROTOCOL_DATA::GetLineNumber(void) const
{
   return f_LineNumber;
}

///
/// \fn GetVerticalIdentifier
/// \brief Get vertical identifier
/// \return Word \e Vertical identifier
///
Word CLASS_CAMERA_PROTOCOL_DATA::GetVerticalIdentifier(void) const
{
   return f_VerticalResolution;
}

///
/// \fn GetHorizontalIdentifier
/// \brief Get horizontal identifier
/// \return Word \e horizontal identifier
///
Word CLASS_CAMERA_PROTOCOL_DATA::GetHorizontalIdentifier(void) const
{
   return f_HorizontalResolution;
}

/******************************************************************************
 *                                  Setter                                    *
 *****************************************************************************/

///
/// \fn SetImageID
/// \brief Set image identifier
/// \param[in] imageID : image identifier
///
void CLASS_CAMERA_PROTOCOL_DATA::SetImageID(const Word imageID)
{
   f_ImageId = imageID;
}

///
/// \fn SetLineNumber
/// \brief Set line number
/// \param[in] lineNumber : line number
///
void CLASS_CAMERA_PROTOCOL_DATA::SetLineNumber(const Word lineNumber)
{
   f_LineNumber = lineNumber;
}

///
/// \fn SetVerticalResolution
/// \brief Set vertical resolution
/// \param[in] verticalResolution : vertical resolution
///
void CLASS_CAMERA_PROTOCOL_DATA::SetVerticalResolution(const Word verticalResolution)
{
   f_VerticalResolution = verticalResolution;
}

///
/// \fn SetHorizontalResolution
/// \brief Set horizontal resolution
/// \param[in] horizontalResolution : horizontal resolution
///
void CLASS_CAMERA_PROTOCOL_DATA::SetHorizontalResolution(const Word horizontalResolution)
{
   f_HorizontalResolution = horizontalResolution;
}

/******************************************************************************
 *                             Public methods                                 *
 *****************************************************************************/

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

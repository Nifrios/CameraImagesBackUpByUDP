///
/// \file CAMERA_ClassCameraImage.cpp
/// \brief Classe CLASS_CAMERA_IMAGE
/// \author Florian Roussel
/// \date 2018-06-06
///
/// CLASS_CAMERA_IMAGE functions
///

// C++ Standard
// Qt librairies
// Modules
#include "CAMERA_ClassCameraImage.h"

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
/// \fn CLASS_CAMERA_IMAGE(QObject *parent)
/// \brief CLASS_CAMERA_IMAGE constructor
///
/// \param[in] imageID : Image identifier
/// \param[in] verticalResolution : Vertical resolution
/// \param[in] horizontalResolutation : Horizontal resolution
/// \param[in] parent : Objet parent
///
CLASS_CAMERA_IMAGE::CLASS_CAMERA_IMAGE(Word imageID, Word verticalResolution, Word horizontalResolutation, QObject *parent):
   QObject(parent),
   f_ImageId(imageID),
   f_VerticalResolution(verticalResolution),
   f_HorizontalResolution(horizontalResolutation),
   f_Pixels()
{

}

///
/// \fn ~CLASS_CAMERA_IMAGE()
/// \brief CLASS_CAMERA_IMAGE destructor
///
CLASS_CAMERA_IMAGE::~CLASS_CAMERA_IMAGE()
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
Word CLASS_CAMERA_IMAGE::GetImageID(void) const
{
   return f_ImageId;
}

///
/// \fn GetVerticalResolution
/// \brief Get vertical resolution
/// \return Word \e Vertical resolution
///
Word CLASS_CAMERA_IMAGE::GetVerticalResolution(void) const
{
   return f_VerticalResolution;
}

///
/// \fn GetHorizontalResolution
/// \brief Get horizontal resolution
/// \return Word \e horizontal resolution
///
Word CLASS_CAMERA_IMAGE::GetHorizontalResolution(void) const
{
   return f_HorizontalResolution;
}

///
/// \fn GetPixels
/// \brief Get data per line
/// \return QMap<Word, QByteArray> \e Data per line
///
const QMap<Word, QByteArray>& CLASS_CAMERA_IMAGE::GetPixels(void) const
{
   return f_Pixels;
}

/******************************************************************************
 *                                  Setter                                    *
 *****************************************************************************/

/******************************************************************************
 *                             Public methods                                 *
 *****************************************************************************/

///
/// \fn AppendPixelsData
/// \brief Append pixels data in image
/// \param[in] lineNumber : Line number
/// \param[in] pixels : Pixels
///
void CLASS_CAMERA_IMAGE::AppendPixelsData(const Word lineNumber, const QByteArray& pixels)
{
   // If lineNumber is already presents, we erased old data replaces by pixels
   f_Pixels.insert(lineNumber, pixels);
}

///
/// \fn ImageIsReadyToExport
/// \brief Indicate if image contains all wanted data
/// \return Bool \e True if image contains all wanted data
///
Bool CLASS_CAMERA_IMAGE::ImageIsReadyToExport(void)
{
   return (f_Pixels.size() == f_VerticalResolution);
}

/******************************************************************************
 *                               Public slots                                 *
 *****************************************************************************/

/******************************************************************************
 *                              Private methods                               *
 *****************************************************************************/

QT -= gui
QT += serialport network core

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Version number
VERSION = 0.0
DEFINES += VERSION=$$VERSION

# Disable all optimisations in Debug mode
QMAKE_CXXFLAGS_DEBUG -= -O2
QMAKE_CFLAGS_DEBUG -= -O2
QMAKE_CXXFLAGS_DEBUG += -O0
QMAKE_CFLAGS_DEBUG += -O0

# Activate all warnings and Warnings are considered like errors
QMAKE_CXXFLAGS += -Wall -Wextra

# Configurations des répertoires de destination de la génération
OBJECTS_DIR = ./objects_dir
MOC_DIR = ./moc_dir
RCC_DIR = ./rcc_dir
UI_DIR = ./ui_dir

SOURCES += \
        main.cpp \
    CAMERA_ClassCameraDataManager.cpp \
    PROTOCOL/CAMERA_ClassCameraProtocolDecode.cpp \
    PROTOCOL/CAMERA_ClassCameraProtocolData.cpp \
    CAMERA_ClassCameraImage.cpp \
    COMDRIVER/COMDRIVER_ClassUdp.cpp

HEADERS += \
    COMMON_TypeDefs.h \
    CAMERA_ClassCameraDataManager.h \
    PROTOCOL/CAMERA_ClassCameraProtocolDecode.h \
    PROTOCOL/CAMERA_ClassCameraProtocolData.h \
    CAMERA_ClassCameraImage.h \
    COMDRIVER/COMDRIVER_ClassUdp.h

INCLUDEPATH += \
   $$PWD \
   $$PWD/COMDRIVER \
   $$PWD/PROTOCOL \

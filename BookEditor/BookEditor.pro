#-------------------------------------------------
#
# Project created by QtCreator 2018-02-10T11:13:47
#
#-------------------------------------------------

QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = BookEditor
TEMPLATE = app

CONFIG  -= app_bundle
DEFINES += QT_MESSAGELOGCONTEXT
DEFINES += QT_DEPRECATED_WARNINGS

# Output directory
CONFIG(debug, debug|release) {
    output = debug
}
CONFIG(release, debug|release) {
    output = release
}

DESTDIR     = bin
OBJECTS_DIR = $$output
MOC_DIR     = $$output
RCC_DIR     = $$output
UI_DIR      = $$output

include(gui/gui.pri)
include(util/util.pri)
include(bean/bean.pri)
include(service/service.pri)

SOURCES += \
        main.cpp

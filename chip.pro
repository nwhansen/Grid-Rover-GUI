RESOURCES += images.qrc

HEADERS += mainwindow.h view.h  \
    dummymodel.h
SOURCES += main.cpp \
    dummymodel.cpp
SOURCES += mainwindow.cpp view.cpp

contains(QT_CONFIG, opengl):QT += opengl

DEFINES += QT_NO_OPENGL

build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

# install
target.path = $$[QT_INSTALL_DEMOS]/chip
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.png *.pro *.html *.doc images
sources.path = $$[QT_INSTALL_DEMOS]/chip
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)

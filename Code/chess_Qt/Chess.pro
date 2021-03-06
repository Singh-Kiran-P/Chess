QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AIPlayer.cpp \
    bishop.cpp \
    board.cpp \
    boardscene.cpp \
    button.cpp \
    game.cpp \
    gamewindow.cpp \
    humanplayer.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    pawn.cpp \
    piece.cpp \
    pieceview.cpp \
    player.cpp \
    queen.cpp \
    rook.cpp \
    tileview.cpp

HEADERS += \
    AIplayer.h \
    bishop.h \
    board.h \
    boardscene.h \
    button.h \
    game.h \
    gamewindow.h \
    humanplayer.h \
    king.h \
    knight.h \
    pawn.h \
    piece.h \
    pieceview.h \
    player.h \
    queen.h \
    resource.h \
    rook.h \
    tileview.h

FORMS += \
    mainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

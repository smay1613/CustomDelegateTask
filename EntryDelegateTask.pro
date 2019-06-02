QT += quick
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    src/contactsmodel.cpp \
    src/basiccontact.cpp \
    src/contactsuggestion.cpp \
    src/cachestorage.cpp

RESOURCES += qml.qrc
INCLUDEPATH = include/

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = "."


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/contactsmodel.h \
    include/icontact.h \
    include/basiccontact.h \
    include/vcardinfo.h \
    include/contactsuggestion.h \
    include/cachestorage.h

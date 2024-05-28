QT += opengl widgets
LIBS+= -lopengl32 -glu32

DISTFILES += \
    CMakeLists.txt \
    CMakeLists.txt.user \
    open.pro.user

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp

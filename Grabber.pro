######################################################################
# Automatically generated by qmake (2.01a) dim. 15. avr. 20:57:23 2012
######################################################################

TEMPLATE = app
TARGET =
DEPENDPATH += . debug includes languages release source ui
INCLUDEPATH += . includes source

BREAKPAD = D:/Programmation/C++/Qt/google-breakpad
INCLUDEPATH += $${BREAKPAD}/src
LIBS += $${BREAKPAD}/src/client/windows/Release/lib/common.lib \
		$${BREAKPAD}/src/client/windows/Release/lib/crash_generation_client.lib \
		$${BREAKPAD}/src/client/windows/Release/lib/exception_handler.lib
#LIBS += -lcommon -lcrash_generation_client -lexception_handler

# Input
HEADERS += includes/aboutwindow.h \
		   includes/addgroupwindow.h \
		   includes/adduniquewindow.h \
		   includes/batchwindow.h \
		   includes/blacklistfix.h \
		   includes/blacklistfix2.h \
		   includes/blacklistfix3.h \
		   includes/customwindow.h \
		   includes/detailswindow.h \
		   includes/emptydirsfix.h \
		   includes/emptydirsfix2.h \
		   includes/favoritewindow.h \
		   includes/conditionwindow.h \
		   includes/functions.h \
		   includes/image.h \
		   includes/imagethread.h \
		   includes/json.h \
		   includes/mainwindow.h \
		   includes/optionswindow.h \
		   includes/page.h \
		   includes/pool.h \
		   includes/QAffiche.h \
		   includes/QBouton.h \
		   includes/searchtab.h \
		   includes/searchwindow.h \
		   includes/sitewindow.h \
		   includes/sourceswindow.h \
		   includes/startwindow.h \
		   includes/tag.h \
		   includes/textedit.h \
		   includes/zoomwindow.h \
		   includes/filenamewindow.h \
		   includes/pool.h \
		   includes/pooltab.h \
		   includes/tagtab.h \
		   includes/favoritestab.h \
		   includes/md5fix.h \
		   includes/commands.h \
		   includes/crashhandler.h
FORMS += ui/aboutwindow.ui \
		 ui/adduniquewindow.ui \
		 ui/batchwindow.ui \
		 ui/blacklistfix.ui \
		 ui/blacklistfix2.ui \
		 ui/blacklistfix3.ui \
		 ui/customwindow.ui \
		 ui/detailswindow.ui \
		 ui/emptydirsfix.ui \
		 ui/emptydirsfix2.ui \
		 ui/favoritewindow.ui \
		 ui/conditionwindow.ui \
		 ui/mainwindow.ui \
		 ui/optionswindow.ui \
		 ui/searchwindow.ui \
		 ui/sitewindow.ui \
		 ui/sourceswindow.ui \
		 ui/startwindow.ui \
		 ui/zoomwindow.ui \
		 ui/filenamewindow.ui \
		 ui/pooltab.ui \
		 ui/favoritestab.ui \
		 ui/md5fix.ui \
		 ui/tagtab.ui
SOURCES += source/aboutwindow.cpp \
		   source/addgroupwindow.cpp \
		   source/adduniquewindow.cpp \
		   source/batchwindow.cpp \
		   source/blacklistfix.cpp \
		   source/blacklistfix2.cpp \
		   source/blacklistfix3.cpp \
		   source/customwindow.cpp \
		   source/detailswindow.cpp \
		   source/emptydirsfix.cpp \
		   source/emptydirsfix2.cpp \
		   source/favoritewindow.cpp \
		   source/conditionwindow.cpp \
		   source/functions.cpp \
		   source/image.cpp \
		   source/imagethread.cpp \
		   source/json.cpp \
		   source/main.cpp \
		   source/mainwindow.cpp \
		   source/optionswindow.cpp \
		   source/page.cpp \
		   source/pool.cpp \
		   source/QAffiche.cpp \
		   source/QBouton.cpp \
		   source/searchtab.cpp \
		   source/searchwindow.cpp \
		   source/sitewindow.cpp \
		   source/sourceswindow.cpp \
		   source/startwindow.cpp \
		   source/tag.cpp \
		   source/textedit.cpp \
		   source/zoomwindow.cpp \
		   source/filenamewindow.cpp \
		   source/pooltab.cpp \
		   source/tagtab.cpp \
		   source/favoritestab.cpp \
		   source/md5fix.cpp \
		   source/commands.cpp \
		   source/crashhandler.cpp

RESOURCES += resources.qrc
RC_FILE = icon.rc
TRANSLATIONS += languages/English.ts languages/Fran�ais.ts languages/Russian.ts
QT += network xml sql
CONFIG += designer plugin
CODECFORTR = UTF-8
LIBS += -lqscintilla2

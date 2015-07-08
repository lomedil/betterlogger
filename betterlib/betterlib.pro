TEMPLATE = lib
CONFIG += staticlib
QT -= gui
QT += network websockets
TARGET = better
DESTDIR = ./bin

defineReplace(dirFiles){
  dir = $$1/*
  selected_entries =
  all_entries = $$files($$dir)
  # For every entry: select it if it isn't a folder
  for(entry, all_entries):!exists($$entry/*):selected_entries += $$entry
  return($$selected_entries)
}

INCLUDEPATH = \
                ./include

HEADERS +=   $$dirFiles(./include)

SOURCES = $$dirFiles(./src)

MOC_DIR = ./temp
UI_DIR = ./temp


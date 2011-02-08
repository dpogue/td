#############################################################################
# Makefile for building: bin/td.app/Contents/MacOS/td
# Generated by qmake (2.01a) (Qt 4.7.0) on: Tue Feb 8 13:43:06 2011
# Project:  td.pro
# Template: app
# Command: /usr/bin/qmake -o td.xcodeproj/project.pbxproj td.pro
#############################################################################

MOC       = /Developer/Tools/Qt/moc
UIC       = /Developer/Tools/Qt/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
INCPATH       = -I/usr/local/Qt4.7/mkspecs/macx-xcode -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtNetwork.framework/Versions/4/Headers -I/usr/include/QtNetwork -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -I3rdparty/inc/libtiled -I. -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers -F/Library/Frameworks
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compilers: ./moc_MainWindow.cpp ./moc_manager.cpp ./moc_netclient.cpp\
	 ./moc_CDriver.cpp ./moc_Effect.cpp ./moc_GameObject.cpp\
	 ./moc_InputComponent.cpp ./moc_NPC.cpp ./moc_PlayerInputComponent.cpp\
	 ./moc_PhysicsComponent.cpp ./moc_Player.cpp ./moc_Projectile.cpp\
	 ./moc_SDriver.cpp ./moc_Tile.cpp ./moc_PlayerGraphicsComponent.cpp\
	 ./moc_GraphicsComponent.cpp ./moc_mapdisplayer.cpp
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_MainWindow.cpp moc_manager.cpp moc_netclient.cpp moc_CDriver.cpp moc_Effect.cpp moc_GameObject.cpp moc_InputComponent.cpp moc_NPC.cpp moc_PlayerInputComponent.cpp moc_PhysicsComponent.cpp moc_Player.cpp moc_Projectile.cpp moc_SDriver.cpp moc_Tile.cpp moc_PlayerGraphicsComponent.cpp moc_GraphicsComponent.cpp moc_mapdisplayer.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_manager.cpp moc_netclient.cpp moc_CDriver.cpp moc_Effect.cpp moc_GameObject.cpp moc_InputComponent.cpp moc_NPC.cpp moc_PlayerInputComponent.cpp moc_PhysicsComponent.cpp moc_Player.cpp moc_Projectile.cpp moc_SDriver.cpp moc_Tile.cpp moc_PlayerGraphicsComponent.cpp moc_GraphicsComponent.cpp moc_mapdisplayer.cpp
moc_MainWindow.cpp: src/engine/GraphicsComponent.h \
		src/MainWindow.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/MainWindow.h -o moc_MainWindow.cpp

moc_manager.cpp: src/audio/manager.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/audio/manager.h -o moc_manager.cpp

moc_netclient.cpp: src/network/netclient.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/network/netclient.h -o moc_netclient.cpp

moc_CDriver.cpp: src/engine/Player.h \
		src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/PhysicsComponent.h \
		src/engine/InputComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/PlayerInputComponent.h \
		src/engine/PlayerPhysicsComponent.h \
		src/engine/PlayerGraphicsComponent.h \
		src/MainWindow.h \
		src/engine/CDriver.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/CDriver.h -o moc_CDriver.cpp

moc_Effect.cpp: src/engine/PhysicsComponent.h \
		src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/InputComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/Effect.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/Effect.h -o moc_Effect.cpp

moc_GameObject.cpp: src/engine/PhysicsComponent.h \
		src/engine/GameObject.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/GameObject.h -o moc_GameObject.cpp

moc_InputComponent.cpp: src/engine/InputComponent.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/InputComponent.h -o moc_InputComponent.cpp

moc_NPC.cpp: src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/PhysicsComponent.h \
		src/engine/InputComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/NPC.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/NPC.h -o moc_NPC.cpp

moc_PlayerInputComponent.cpp: src/engine/InputComponent.h \
		src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/PhysicsComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/PlayerInputComponent.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/PlayerInputComponent.h -o moc_PlayerInputComponent.cpp

moc_PhysicsComponent.cpp: src/engine/PhysicsComponent.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/PhysicsComponent.h -o moc_PhysicsComponent.cpp

moc_Player.cpp: src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/PhysicsComponent.h \
		src/engine/InputComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/PlayerInputComponent.h \
		src/engine/Player.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/Player.h -o moc_Player.cpp

moc_Projectile.cpp: src/engine/Unit.h \
		src/engine/GameObject.h \
		src/engine/PhysicsComponent.h \
		src/engine/InputComponent.h \
		src/engine/GraphicsComponent.h \
		src/engine/Projectile.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/Projectile.h -o moc_Projectile.cpp

moc_SDriver.cpp: src/engine/SDriver.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/SDriver.h -o moc_SDriver.cpp

moc_Tile.cpp: src/engine/Tile.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/Tile.h -o moc_Tile.cpp

moc_PlayerGraphicsComponent.cpp: src/engine/GraphicsComponent.h \
		src/engine/PlayerGraphicsComponent.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/PlayerGraphicsComponent.h -o moc_PlayerGraphicsComponent.cpp

moc_GraphicsComponent.cpp: src/engine/GraphicsComponent.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/engine/GraphicsComponent.h -o moc_GraphicsComponent.cpp

moc_mapdisplayer.cpp: src/graphics/mapdisplayer.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/graphics/mapdisplayer.h -o moc_mapdisplayer.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 


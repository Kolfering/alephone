## Process this file with automake to produce Makefile.in 

noinst_LIBRARIES = libmisc.a

if MAKE_WINDOWS
THREAD_PRIORITY = thread_priority_sdl_win32.cpp
else
THREAD_PRIORITY = thread_priority_sdl_posix.cpp
endif

if STEAM
STEAMSHIM_CHILD = steamshim_child.cpp 
else
STEAMSHIM_CHILD =
endif

libmisc_a_SOURCES = achievements.h ActionQueues.h alephversion.h binders.h CircularByteBuffer.h \
  CircularQueue.h Console.h DefaultStringSets.h game_errors.h \
  interface.h interface_menus.h key_definitions.h Logging.h \
  PlayerImage_sdl.h \
  PlayerName.h preference_dialogs.h preferences.h \
  preferences_widgets_sdl.h progress.h Random.h Scenario.h sdl_dialogs.h \
  sdl_widgets.h shared_widgets.h thread_priority_sdl.h vbl_definitions.h vbl.h VecOps.h \
  WindowedNthElementFinder.h AlephSansMono-Bold.h powered_by_alephone.h powered_by_alephone_h.h \
  Statistics.h ScenarioChooser.h \
  \
  achievements.cpp ActionQueues.cpp CircularByteBuffer.cpp Console.cpp DefaultStringSets.cpp game_errors.cpp \
  interface.cpp \
  Logging.cpp PlayerImage_sdl.cpp PlayerName.cpp preferences.cpp \
  preference_dialogs.cpp preferences_widgets_sdl.cpp Scenario.cpp sdl_dialogs.cpp $(THREAD_PRIORITY) \
  sdl_widgets.cpp shared_widgets.cpp vbl.cpp \
  Statistics.cpp ScenarioChooser.cpp \
  ProFontAO.h CourierPrime.h CourierPrimeBold.h CourierPrimeItalic.h CourierPrimeBoldItalic.h \
  $(STEAMSHIM_CHILD)

EXTRA_libmisc_a_SOURCES = alephone.xpm alephone32.xpm thread_priority_sdl_posix.cpp thread_priority_sdl_dummy.cpp thread_priority_sdl_win32.cpp thread_priority_sdl_macosx.cpp m1_achievements.lua m2_achievements.lua inf_achievements.lua steamshim_child.h steamshim_child.cpp

AM_CPPFLAGS = -I$(top_srcdir)/Source_Files/CSeries -I$(top_srcdir)/Source_Files/Files \
  -I$(top_srcdir)/Source_Files/GameWorld -I$(top_srcdir)/Source_Files/Input \
  -I$(top_srcdir)/Source_Files/Lua -I$(top_srcdir)/Source_Files/ModelView -I$(top_srcdir)/Source_Files/Network \
  -I$(top_srcdir)/Source_Files/Network/Metaserver \
  -I$(top_srcdir)/Source_Files/Videos -I$(top_srcdir)/Source_Files/RenderMain \
  -I$(top_srcdir)/Source_Files/RenderOther -I$(top_srcdir)/Source_Files/Sound \
  -I$(top_srcdir)/Source_Files/TCPMess \
  -I$(top_srcdir)/Source_Files/XML \
  -I$(top_srcdir)/Source_Files

## Process this file with automake to produce Makefile.in 

bin_PROGRAMS = tests

tests_SOURCES = replay_film_test.cpp main.cpp

tests_LDADD = \
  $(top_srcdir)/Source_Files/CSeries/libcseries.a $(top_srcdir)/Source_Files/Files/libfiles.a \
  $(top_srcdir)/Source_Files/FFmpeg/libffmpeg.a $(top_srcdir)/Source_Files/GameWorld/libgameworld.a \
  $(top_srcdir)/Source_Files/Input/libinput.a $(top_srcdir)/Source_Files/Lua/liba1lua.a \
  $(top_srcdir)/Source_Files/Misc/libmisc.a $(top_srcdir)/Source_Files/ModelView/libmodelview.a \
  $(top_srcdir)/Source_Files/Network/libnetwork.a $(top_srcdir)/Source_Files/Network/Metaserver/libmetaserver.a \
  $(top_srcdir)/Source_Files/RenderMain/librendermain.a $(top_srcdir)/Source_Files/RenderOther/librenderother.a \
  $(top_srcdir)/Source_Files/Sound/libsound.a $(top_srcdir)/Source_Files/TCPMess/libtcpmess.a $(top_srcdir)/Source_Files/XML/libxml.a

AM_CPPFLAGS = -I$(top_srcdir)/Source_Files/CSeries -I$(top_srcdir)/Source_Files/Files \
  -I$(top_srcdir)/Source_Files/GameWorld -I$(top_srcdir)/Source_Files/Input \
  -I$(top_srcdir)/Source_Files/Lua -I$(top_srcdir)/Source_Files/Misc \
  -I$(top_srcdir)/Source_Files/ModelView -I$(top_srcdir)/Source_Files/Network \
  -I$(top_srcdir)/Source_Files/Network/Metaserver \
  -I$(top_srcdir)/Source_Files/FFmpeg -I$(top_srcdir)/Source_Files/RenderMain \
  -I$(top_srcdir)/Source_Files/RenderOther -I$(top_srcdir)/Source_Files/Sound \
  -I$(top_srcdir)/Source_Files/XML -I$(top_srcdir)/Source_Files/TCPMess \
  -I$(top_srcdir)/Source_Files
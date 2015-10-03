# Note: plugindir is set in configure

plugin_LTLIBRARIES = libdropper.la

# sources used to compile this plug-in
libdropper_la_SOURCES = drop.c drop.h

# compiler and linker flags used to compile this plugin, set in configure.ac
libdropper_la_CFLAGS = $(GST_CFLAGS)
libdropper_la_LIBADD = $(GST_LIBS)
libdropper_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libdropper_la_LIBTOOLFLAGS = --tag=disable-static

# headers we need but don't want installed
noinst_HEADERS = drop.h

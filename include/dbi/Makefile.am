## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = foreign

# we use exec here to install the headers with the library, not with
# the docs when using install-data and install-exec
includeexecdir = $(prefix)/include/dbi

includeexec_HEADERS = dbi.h dbi-dev.h dbd.h

EXTRA_DIST = dbi.h.in

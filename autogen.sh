#!/bin/sh
# autogen.sh - generates configure using the autotools
# $Id: autogen.sh,v 1.2 2003/07/09 07:24:52 dap24 Exp $
libtoolize --force --copy
aclocal
autoheader
automake --add-missing

echo
echo "Using `autoconf --version`, if you have problems"
echo "while building then edit autogen.sh and rerun it..."
echo
autoconf

## autoconf 2.53 will not work, at least on FreeBSD. Change the following
## line appropriately to call autoconf 2.13 instead. This one works for
## FreeBSD 4.7:
#autoconf213


/*
 * libdbi - database independent abstraction layer for C.
 * Copyright (C) 2001, David Parker and Mark Tobenkin.
 * http://libdbi.sourceforge.net
 * 
 * dbd_mysql.c: MySQL database support (using libmysqlclient6)
 * Copyright (C) 2001, Mark M. Tobenkin <mark@brentwoodradio.com>.
 * http://libdbi.sourceforge.net
 * 
 * $Id: dbd_template.h,v 1.1 2001/08/15 19:20:47 dap24 Exp $
 */

#define TEMPLATE_RESERVED_WORDS { \
	"INT", \
	"NULL", \
	"SELECT", \
	"UPDATE", \
	"etc...", \
	NULL }

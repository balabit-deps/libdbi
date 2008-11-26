/*
 * libdbi - database independent abstraction layer for C.
 * Copyright (C) 2001-2003, David Parker and Mark Tobenkin.
 * http://libdbi.sourceforge.net
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * $Id: timegm.c,v 1.2 2008/11/26 23:55:56 mhoenicka Exp $
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <time.h>

#ifndef HAVE_TIMEGM

time_t timegm(struct tm *tm) {
  time_t temp_ltime;
  struct tm temp_gm;

  if (!tm) {
    temp_ltime = 0;
  }
  else {
    temp_ltime = mktime(tm);
  }

  gmtime_r(&temp_ltime, &temp_gm);

  return (time_t)(temp_ltime + (temp_ltime - mktime(&temp_gm)));
}

#endif /* HAVE_TIMEGM */

/*
 * libdbi - database independent abstraction layer for C.
 * Copyright (C) 2001, David Parker and Mark Tobenkin.
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
 * $Id: dbd.h,v 1.5 2001/08/15 19:20:47 dap24 Exp $
 */

#ifndef __DBD_H__
#define __DBD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dbi/dbi.h>
#include <dbi/dbi-dev.h>

/* FUNCTIONS EXPORTED BY EACH PLUGIN */
void dbd_register_plugin(const dbi_info_t **_plugin_info, const char ***_custom_functions, const char ***_reserved_words);
int dbd_initialize(dbi_plugin_t *plugin);
int dbd_connect(dbi_driver_t *driver);
int dbd_disconnect(dbi_driver_t *driver);
int dbd_fetch_row(dbi_result_t *result, unsigned int rownum);
int dbd_free_query(dbi_result_t *result);
int dbd_goto_row(dbi_result_t *result, unsigned int row);
dbi_result_t *dbd_list_dbs(dbi_driver_t *driver);
dbi_result_t *dbd_list_tables(dbi_driver_t *driver, const char *db);
dbi_result_t *dbd_query(dbi_driver_t *driver, const char *statement);
int dbd_quote_string(dbi_plugin_t *plugin, const char *orig, char *dest);
char *dbd_select_db(dbi_driver_t *driver, const char *db);
int dbd_geterror(dbi_driver_t *driver, int *errno, char **errstr);

/* _DBD_* PLUGIN AUTHORS HELPER FUNCTIONS */
dbi_result_t *_dbd_result_create(dbi_driver_t *driver, void *handle, unsigned int numrows_matched, unsigned int numrows_affected);
void _dbd_result_set_numfields(dbi_result_t *result, unsigned int numfields);
void _dbd_result_add_field(dbi_result_t *result, unsigned int idx, char *name, unsigned short type, unsigned int attribs);
dbi_row_t *_dbd_row_allocate(unsigned int numfields);
void _dbd_row_finalize(dbi_result_t *result, dbi_row_t *row, unsigned int idx);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* __DBD_H__ */

/*
 * libdbi - database independent abstraction layer for C.
 * Copyright (C) 2001-2002, David Parker and Mark Tobenkin.
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
 * $Id: dbi.h,v 1.28 2002/03/29 03:57:54 dap Exp $
 */

#ifndef __DBI_H__
#define __DBI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

/* opaque type definitions */
typedef void * dbi_driver;
typedef void * dbi_conn;
typedef void * dbi_result;

/* values for the int in field_types[] */
#define DBI_TYPE_INTEGER 1
#define DBI_TYPE_DECIMAL 2
#define DBI_TYPE_STRING 3
#define DBI_TYPE_BINARY 4
#define DBI_TYPE_ENUM 5
#define DBI_TYPE_SET 6
#define DBI_TYPE_DATETIME 7

/* values for the bitmask in field_type_attributes[] */
#define DBI_INTEGER_UNSIGNED 1
#define DBI_INTEGER_SIZE1 2
#define DBI_INTEGER_SIZE2 4
#define DBI_INTEGER_SIZE3 8
#define DBI_INTEGER_SIZE4 16
#define DBI_INTEGER_SIZE8 32
#define DBI_DECIMAL_UNSIGNED 1
#define DBI_DECIMAL_SIZE4 2
#define DBI_DECIMAL_SIZE8 4
#define DBI_STRING_FIXEDSIZE 1 /* XXX unused as of now */
#define DBI_DATETIME_DATE 1
#define DBI_DATETIME_TIME 2

int dbi_initialize(const char *driverdir);
void dbi_shutdown();
const char *dbi_version();

dbi_driver dbi_driver_list(dbi_driver Current); /* returns next driver. if current is NULL, return first driver. */
dbi_driver dbi_driver_open(const char *name); /* goes thru linked list until it finds the right one */
int dbi_driver_is_reserved_word(dbi_driver Driver, const char *word);
void *dbi_driver_specific_function(dbi_driver Driver, const char *name);
int dbi_driver_quote_string(dbi_driver Driver, char **orig);

const char *dbi_driver_get_name(dbi_driver Driver);
const char *dbi_driver_get_filename(dbi_driver Driver);
const char *dbi_driver_get_description(dbi_driver Driver);
const char *dbi_driver_get_maintainer(dbi_driver Driver);
const char *dbi_driver_get_url(dbi_driver Driver);
const char *dbi_driver_get_version(dbi_driver Driver);
const char *dbi_driver_get_date_compiled(dbi_driver Driver);

dbi_conn dbi_conn_new(const char *name); /* shortcut for dbi_conn_open(dbi_driver_open("foo")) */
dbi_conn dbi_conn_open(dbi_driver Driver); /* returns an actual instance of the conn */
dbi_driver dbi_conn_get_driver(dbi_conn Conn);
int dbi_conn_set_option(dbi_conn Conn, const char *key, char *value); /* if value is NULL, remove option from list */
int dbi_conn_set_option_numeric(dbi_conn Conn, const char *key, int value);
const char *dbi_conn_get_option(dbi_conn Conn, const char *key);
int dbi_conn_get_option_numeric(dbi_conn Conn, const char *key);
const char *dbi_conn_get_option_list(dbi_conn Conn, const char *current); /* returns key of next option, or the first option key if current is NULL */
void dbi_conn_clear_option(dbi_conn Conn, const char *key);
void dbi_conn_clear_options(dbi_conn Conn);
void dbi_conn_close(dbi_conn Conn);

int dbi_conn_error(dbi_conn Conn, const char **errmsg_dest);
void dbi_conn_error_handler(dbi_conn Conn, void *function, void *user_argument);

int dbi_conn_connect(dbi_conn Conn);
int dbi_conn_get_socket(dbi_conn Conn);
dbi_result dbi_conn_get_db_list(dbi_conn Conn, const char *pattern);
dbi_result dbi_conn_get_table_list(dbi_conn Conn, const char *db, const char *pattern);
dbi_result dbi_conn_query(dbi_conn Conn, const char *formatstr, ...); 
dbi_result dbi_conn_query_null(dbi_conn Conn, const unsigned char *statement, unsigned long st_length); 
int dbi_conn_select_db(dbi_conn Conn, const char *db);

dbi_conn dbi_result_get_conn(dbi_result Result);
int dbi_result_free(dbi_result Result);
int dbi_result_seek_row(dbi_result Result, unsigned int row);
int dbi_result_first_row(dbi_result Result);
int dbi_result_last_row(dbi_result Result);
int dbi_result_prev_row(dbi_result Result);
int dbi_result_next_row(dbi_result Result);
unsigned int dbi_result_get_numrows(dbi_result Result);
unsigned int dbi_result_get_numrows_affected(dbi_result Result);
unsigned int dbi_result_get_field_size(dbi_result Result, const char *fieldname);
unsigned int dbi_result_get_field_size_idx(dbi_result Result, unsigned int idx);
unsigned int dbi_result_get_field_length(dbi_result Result, const char *fieldname); /* size-1 */
unsigned int dbi_result_get_field_length_idx(dbi_result Result, unsigned int idx);
int dbi_result_get_field_idx(dbi_result Result, const char *fieldname);
const char *dbi_result_get_field_name(dbi_result Result, unsigned int idx);
unsigned int dbi_result_get_numfields(dbi_result Result);
unsigned short dbi_result_get_field_type(dbi_result Result, const char *fieldname);
unsigned short dbi_result_get_field_type_idx(dbi_result Result, unsigned int idx);
unsigned long dbi_result_get_field_attrib(dbi_result Result, const char *fieldname, unsigned long attribmin, unsigned long attribmax);
unsigned long dbi_result_get_field_attrib_idx(dbi_result Result, unsigned int idx, unsigned long attribmin, unsigned long attribmax);
unsigned long dbi_result_get_field_attribs(dbi_result Result, const char *fieldname);
unsigned long dbi_result_get_field_attribs_idx(dbi_result Result, unsigned int idx);

int dbi_result_get_fields(dbi_result Result, const char *format, ...);
int dbi_result_bind_fields(dbi_result Result, const char *format, ...);

signed char dbi_result_get_char(dbi_result Result, const char *fieldname);
unsigned char dbi_result_get_uchar(dbi_result Result, const char *fieldname);
short dbi_result_get_short(dbi_result Result, const char *fieldname);
unsigned short dbi_result_get_ushort(dbi_result Result, const char *fieldname);
long dbi_result_get_long(dbi_result Result, const char *fieldname);
unsigned long dbi_result_get_ulong(dbi_result Result, const char *fieldname);
long long dbi_result_get_longlong(dbi_result Result, const char *fieldname);
unsigned long long dbi_result_get_ulonglong(dbi_result Result, const char *fieldname);

float dbi_result_get_float(dbi_result Result, const char *fieldname);
double dbi_result_get_double(dbi_result Result, const char *fieldname);

const char *dbi_result_get_string(dbi_result Result, const char *fieldname);
const unsigned char *dbi_result_get_binary(dbi_result Result, const char *fieldname);

char *dbi_result_get_string_copy(dbi_result Result, const char *fieldname);
unsigned char *dbi_result_get_binary_copy(dbi_result Result, const char *fieldname);

const char *dbi_result_get_enum(dbi_result Result, const char *fieldname);
const char *dbi_result_get_set(dbi_result Result, const char *fieldname);

time_t dbi_result_get_datetime(dbi_result Result, const char *fieldname);

int dbi_result_bind_char(dbi_result Result, const char *fieldname, char *bindto);
int dbi_result_bind_uchar(dbi_result Result, const char *fieldname, unsigned char *bindto);
int dbi_result_bind_short(dbi_result Result, const char *fieldname, short *bindto);
int dbi_result_bind_ushort(dbi_result Result, const char *fieldname, unsigned short *bindto);
int dbi_result_bind_long(dbi_result Result, const char *fieldname, long *bindto);
int dbi_result_bind_ulong(dbi_result Result, const char *fieldname, unsigned long *bindto);
int dbi_result_bind_longlong(dbi_result Result, const char *fieldname, long long *bindto);
int dbi_result_bind_ulonglong(dbi_result Result, const char *fieldname, unsigned long long *bindto);

int dbi_result_bind_float(dbi_result Result, const char *fieldname, float *bindto);
int dbi_result_bind_double(dbi_result Result, const char *fieldname, double *bindto);

int dbi_result_bind_string(dbi_result Result, const char *fieldname, const char **bindto);
int dbi_result_bind_binary(dbi_result Result, const char *fieldname, const unsigned char **bindto);

int dbi_result_bind_string_copy(dbi_result Result, const char *fieldname, char **bindto);
int dbi_result_bind_binary_copy(dbi_result Result, const char *fieldname, unsigned char **bindto);

int dbi_result_bind_enum(dbi_result Result, const char *fieldname, const char **bindto);
int dbi_result_bind_set(dbi_result Result, const char *fieldname, const char **bindto);

int dbi_result_bind_datetime(dbi_result Result, const char *fieldname, time_t *bindto);

/* and now for the same exact thing in index form: */

signed char dbi_result_get_char_idx(dbi_result Result, unsigned int idx);
unsigned char dbi_result_get_uchar_idx(dbi_result Result, unsigned int idx);
short dbi_result_get_short_idx(dbi_result Result, unsigned int idx);
unsigned short dbi_result_get_ushort_idx(dbi_result Result, unsigned int idx);
long dbi_result_get_long_idx(dbi_result Result, unsigned int idx);
unsigned long dbi_result_get_ulong_idx(dbi_result Result, unsigned int idx);
long long dbi_result_get_longlong_idx(dbi_result Result, unsigned int idx);
unsigned long long dbi_result_get_ulonglong_idx(dbi_result Result, unsigned int idx);

float dbi_result_get_float_idx(dbi_result Result, unsigned int idx);
double dbi_result_get_double_idx(dbi_result Result, unsigned int idx);

const char *dbi_result_get_string_idx(dbi_result Result, unsigned int idx);
const unsigned char *dbi_result_get_binary_idx(dbi_result Result, unsigned int idx);

char *dbi_result_get_string_copy_idx(dbi_result Result, unsigned int idx);
unsigned char *dbi_result_get_binary_copy_idx(dbi_result Result, unsigned int idx);

const char *dbi_result_get_enum_idx(dbi_result Result, unsigned int idx);
const char *dbi_result_get_set_idx(dbi_result Result, unsigned int idx);

time_t dbi_result_get_datetime_idx(dbi_result Result, unsigned int idx);

/*
int dbi_result_bind_char_idx(dbi_result Result, unsigned int idx, char *bindto);
int dbi_result_bind_uchar_idx(dbi_result Result, unsigned int idx, unsigned char *bindto);
int dbi_result_bind_short_idx(dbi_result Result, unsigned int idx, short *bindto);
int dbi_result_bind_ushort_idx(dbi_result Result, unsigned int idx, unsigned short *bindto);
int dbi_result_bind_long_idx(dbi_result Result, unsigned int idx, long *bindto);
int dbi_result_bind_ulong_idx(dbi_result Result, unsigned int idx, unsigned long *bindto);
int dbi_result_bind_longlong_idx(dbi_result Result, unsigned int idx, long long *bindto);
int dbi_result_bind_ulonglong_idx(dbi_result Result, unsigned int idx, unsigned long long *bindto);

int dbi_result_bind_float_idx(dbi_result Result, unsigned int idx, float *bindto);
int dbi_result_bind_double_idx(dbi_result Result, unsigned int idx, double *bindto);

int dbi_result_bind_string_idx(dbi_result Result, unsigned int idx, const char **bindto);
int dbi_result_bind_binary_idx(dbi_result Result, unsigned int idx, const unsigned char **bindto);

int dbi_result_bind_string_copy_idx(dbi_result Result, unsigned int idx, char **bindto);
int dbi_result_bind_binary_copy_idx(dbi_result Result, unsigned int idx, unsigned char **bindto);

int dbi_result_bind_enum_idx(dbi_result Result, unsigned int idx, const char **bindto);
int dbi_result_bind_set_idx(dbi_result Result, unsigned int idx, const char **bindto);

int dbi_result_bind_datetime_idx(dbi_result Result, unsigned int idx, time_t *bindto);
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* __DBI_H__ */

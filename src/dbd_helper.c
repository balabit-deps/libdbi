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
 * $Id: dbd_helper.c,v 1.3 2001/07/31 00:42:40 dap24 Exp $
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

#include <dbi/dbi.h>
#include <dbi/dbi-dev.h>

dbi_result_t *_dbd_result_create(dbi_driver_t *driver, void *handle, unsigned int numrows_matched, unsigned int numrows_affected) {
	dbi_result_t *result = (dbi_result_t *) malloc(sizeof(dbi_result_t));
	if (!result) return NULL;
	result->driver = driver;
	result->result_handle = handle;
	result->numrows_matched = numrows_matched;
	result->numrows_affected = numrows_affected;
	result->field_bindings = NULL;
	result->numfields = 0;
	result->field_names = NULL;
	result->field_types = NULL;
	result->field_attribs = NULL;
	result->result_state = (numrows_matched > 0) ? ROWS_RETURNED : NOTHING_RETURNED;
	result->has_string_fields = 0;
	result->rows = calloc(numrows_matched, sizeof(dbi_row_t *));
	result->currowidx = 0;
	return result;
}

void _dbd_result_set_numfields(dbi_result_t *result, unsigned int numfields) {
	result->numfields = numfields;
	result->field_names = calloc(numfields, sizeof(char *));
	result->field_types = calloc(numfields, sizeof(unsigned short));
	result->field_attribs = calloc(numfields, sizeof(unsigned int));
}

void _dbd_result_add_field(dbi_result_t *result, unsigned int idx, char *name, unsigned short type, unsigned int attribs) {
	if ((type == DBI_TYPE_STRING) || (type == DBI_TYPE_BINARY)) result->has_string_fields++;
	result->field_names[idx] = strdup(name);
	result->field_types[idx] = type;
	result->field_attribs[idx] = attribs;
}

dbi_row_t *_dbd_row_allocate(unsigned int numfields, unsigned int has_string_fields) {
	dbi_row_t *row = malloc(sizeof(dbi_row_t));
	if (!row) return NULL;
	row->field_values = calloc(numfields, sizeof(dbi_data_t));
	if (has_string_fields) {
		row->field_sizes = calloc(numfields, sizeof(unsigned int));
	}
	else {
		row->field_sizes = NULL;
	}
	return row;
}

void _dbd_row_finalize(dbi_result_t *result, dbi_row_t *row, unsigned int idx) {
	/* rowidx is one-based in the DBI user level */
	result->rows[idx+1] = row;
}

unsigned long _dbd_isolate_attrib(unsigned long attribs, unsigned long rangemin, unsigned rangemax) {
	/* hahaha! who woulda ever thunk strawberry's code would come in handy? */
	unsigned short startbit = log(rangemin)/log(2);
	unsigned short endbit = log(rangemax)/log(2);
	//unsigned short numbits = sizeof(attribs) * 8;
	unsigned long attrib_mask = 0;
	int x;
	
/*	// XXX there's probably a better way to do this
	for (x = 0; x < numbits-endbit+1; x++) attribs <<= 1;
	for (x = 0; x < numbits-endbit+1; x++) attribs >>= 1;
	for (x = 0; x < startbit; x++) attribs >>= 1; */

	for (x = startbit; x <= endbit; x++)
		attrib_mask |= (unsigned long) pow(2, x);

	return (attribs & attrib_mask);
}


/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.macro.h - SOL (Simple Object Library) macro header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MACRO_H
#define _SOL_MACRO_H 1

#define SOL_SET_ATTRIBUTE(__a__, __b__, __c__) (*__a__).__b__ = strdup(__c__);

#define SOL_DB_POSTGRES_CONNECTION_STRING(__a__) ({\
 	char __o__[512] = {0};\
	if((*__a__).User != NULL && !__sol_module_string_compare__((*__a__).User, SOL_EMPTY)) {\
		strcat(__o__, "user=");\
		strcat(__o__, (*__a__).User);\
	}\
	if((*__a__).Password != NULL && !__sol_module_string_compare__((*__a__).Password, SOL_EMPTY)) {\
		strcat(__o__, " password=");\
		strcat(__o__, (*__a__).Password);\
	}\
	if((*__a__).Host != NULL && !__sol_module_string_compare__((*__a__).Host, SOL_EMPTY)) {\
		strcat(__o__, " host=");\
		strcat(__o__, (*__a__).Host);\
	}\
	if((*__a__).Port != 0) {\
		strcat(__o__, " port=");\
		strcat(__o__, __sol_module_string_integer_to_string__((*__a__).Port));\
	}\
	if((*__a__).Name != NULL && !__sol_module_string_compare__((*__a__).Name, SOL_EMPTY)) {\
		strcat(__o__, " dbname=");\
		strcat(__o__, (*__a__).Name);\
	}\
	printf("CS: %s\n", __o__);\
	__o__;\
})

#endif

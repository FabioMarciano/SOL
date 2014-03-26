/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.db.h - SOL (Simple Object Library) db module header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MOD_DB_H
#define _SOL_MOD_DB_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
 
__SOF__

// @name	__sol_module_db_new__
// @param	DB pointer
// @param	int type of database
// @return	void
// Creates a new database resource.
extern void __sol_module_db_new__(DB *, DBTYPE);

// @name	__sol_module_db_set_attribute__
// @param	DB pointer
// @param	char attribute name
// @param	char attribute value
// Setup the DB_DATA attribute/value.
extern void __sol_module_db_set_attribute__(DB *, DBATTR, const char *);

// @name	__sol_module_db_set_type__
// @param	char type
// Setup the DB type.
extern void __sol_module_db_set_type__(DB *, DBTYPE);

// @name	__sol_module_db_set_host__
// @param	char hostname
// Setup the DB hostname.
extern void __sol_module_db_set_host__(DB *, const char *);

// @name	__sol_module_db_set_user__
// @param	char database user
// Setup the DB user.
extern void __sol_module_db_set_user__(DB *, const char *);

// @name	__sol_module_db_set_password__
// @param	char database password
// Setup the DB password.
extern void __sol_module_db_set_password__(DB *, const char *);

// @name	__sol_module_db_set_port__
// @param	char database port
// Setup the DB port.
extern void __sol_module_db_set_port__(DB *, int);

// @name	__sol_module_db_set_name__
// @param	char database name
// Setup the DB name.
extern void __sol_module_db_set_name__(DB *, const char *);

// @name	__sol_module_db_status__
// @return	BOLL connection status
// Check the database status
extern BOOL __sol_module_db_status__(DB *);

// @name	__sol_module_db_connect__
// @return	BOLL connection status
// Connect with database.
extern BOOL __sol_module_db_connect__(DB *);

/*
// @name	__sol_module_db_shutdown__
// @return	BOLL connection status
// Disconect with database.
extern void __sol_module_db_shutdown__(DB *);

// @name	__sol_module_db_use__
// @return	BOOL success
// Selects database.
extern BOOL __sol_module_db_use__(DB *, const char *);

// @name	__sol_module_db_merge__
// @param	char table name
// @param	NODE data structure
// @return	char merged fields and data
// Check the table fields and synchronize it with the passed data.
extern char *__sol_module_db_merge__(DB *, const char *, NODE **);
*/
__EOF__

#endif

/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.db.c - SOL (Simple Object Library) db module source file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

// @inc: SOL module header.
#include "SOL/module.h"

__attribute__((constructor)) static void __sol_module_db_init__() {}

__attribute__((destructor)) static void __sol_module_db_quit__() {}

void __sol_module_db_new__(DB *db, DBTYPE driver) {

	(*db).Type = driver;
	(*db).Status = FALSE;

	__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_HOST, SOL_DB_HOST);
	__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_USER, SOL_DB_USER);
	__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_PASSWORD, SOL_DB_PASSWORD);
	__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_NAME, SOL_DB_NAME);

	switch(driver) {
		case 1:
			// (*db).Connection.pgsql = PQconnectdb(SOL_EMPTY);
			__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_NAME, "template1");
			__sol_module_db_set_attribute__(&(*db), DB_ATTRIBUTE_USER, SOL_DB_POSTGRES_USER);
			__sol_module_db_set_port__(&(*db), SOL_DB_POSTGRES_PORT);
		break;
		default:
			mysql_init(&(*db).Connection.mysql);
			__sol_module_db_set_port__(&(*db), SOL_DB_MYSQL_PORT);
		break;
	}
}

void __sol_module_db_set_attribute__(DB *db, DBATTR attribute, const char *value) {
	switch(attribute) {
		case DB_ATTRIBUTE_USER:
			SOL_SET_ATTRIBUTE(&(*db), User, value);
		break;
		case DB_ATTRIBUTE_PASSWORD:
			SOL_SET_ATTRIBUTE(&(*db), Password, value);
		break;
		case DB_ATTRIBUTE_NAME:
			SOL_SET_ATTRIBUTE(&(*db), Name, value);
		break;
		default:
			SOL_SET_ATTRIBUTE(&(*db), Host, value);
		break;
	}
}

void __sol_module_db_set_type__(DB *db, DBTYPE value) {
	(*db).Type = value;
}

void __sol_module_db_set_host__(DB *db, const char *value) {
	SOL_SET_ATTRIBUTE(&(*db), Host, value);
}

void __sol_module_db_set_user__(DB *db, const char *value) {
	SOL_SET_ATTRIBUTE(&(*db), User, value);
}

void __sol_module_db_set_password__(DB *db, const char *value) {
	SOL_SET_ATTRIBUTE(&(*db), Password, value);
}

void __sol_module_db_set_port__(DB *db, int value) {
	(*db).Port = value;
}

void __sol_module_db_set_name__(DB *db, const char *value) {
	SOL_SET_ATTRIBUTE(&(*db), Name, value);
}

BOOL __sol_module_db_status__(DB *db) {
	if(db != NULL) {
		switch((*db).Type) {
			case SOL_DB_TYPE_POSTGRES:
				if((*db).Status != FALSE) {
					(*db).Status = (PQstatus((*db).Connection.pgsql) == CONNECTION_OK) ? TRUE : FALSE;
				}
			break;
			default:
				if((*db).Status != FALSE) {
					(*db).Status = (mysql_ping(&(*db).Connection.mysql) != 0) ? FALSE : TRUE;
				}
			break;
		}
	}

	return (*db).Status;
}

BOOL __sol_module_db_connect__(DB *db) {

	BOOL status = FALSE;

	if(db != NULL) {
		if(!(*db).Status) {
			switch((*db).Type) {
				case SOL_DB_TYPE_POSTGRES:
					(*db).Connection.pgsql = PQconnectdb(SOL_DB_POSTGRES_CONNECTION_STRING(&(*db)));
					if(PQstatus((*db).Connection.pgsql) == CONNECTION_OK) {
						status = TRUE;
					} else {
						status = FALSE;
					}
				break;
				default:
					if(mysql_real_connect((&(*db).Connection.mysql), (*db).Host, (*db).User, (*db).Password, (*db).Name, (*db).Port, NULL, 0)) {
						status = TRUE;
					} else {
						status = FALSE;
					}
				break;
			}
		}
	}

	(*db).Status = status;
	return status;
}

/*

void __sol_module_db_shutdown__(void) {
	if(SOL_DB_STATUS) {
		mysql_close(&SOL_DB_CONNECTION);
	}

	SOL_DB_STATUS = FALSE;
}

BOOL __sol_module_db_use__(const char *database) {
	BOOL output = FALSE;

	if(__sol_module_db_status__()) {
		if(database != NULL) {
			__sol_module_db_set_name__(database);
		}
		output = (mysql_select_db(&SOL_DB_CONNECTION, __sol_module_db_get_name__()) != 0) ? FALSE : TRUE;
	}

	return output;
}

char *__sol_module_db_merge__(const char *table, NODE **data) {
	char *output = NULL;
	return output;
}
*/
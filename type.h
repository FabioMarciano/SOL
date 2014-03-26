/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.type.h - SOL (Simple Object Library) type header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_TYPE_H
#define _SOL_TYPE_H 1

// @typ: CHAR
// Wide Char Definition.
typedef wchar_t CHAR;

// @typ: BOOL
// Logical type definition.
typedef enum {FALSE = 0, TRUE = 1} BOOL;

// @typ: DBATTR
// Database attribute.
typedef enum {DB_ATTRIBUTE_TYPE, DB_ATTRIBUTE_HOST, DB_ATTRIBUTE_USER, DB_ATTRIBUTE_PASSWORD, DB_ATTRIBUTE_PORT, DB_ATTRIBUTE_NAME} DBATTR;

// @typ: struct __sol_node__
// Structure with node implementation.
struct __sol_node__ {
	char *name;
	char *value;
	struct __sol_node__ *attributes;
	struct __sol_node__ *events;
	struct __sol_node__ *childNodes;
	struct __sol_node__ *parentNode;
	struct __sol_node__ *next;
	struct __sol_node__ *previous;
};

typedef struct __sol_node__ NODE;

// @def	DB_TYPE
// Defines database types.
typedef enum {SOL_DB_TYPE_MYSQL, SOL_DB_TYPE_POSTGRES} DBTYPE;

// @typ	struct __sol_node__
// Holds the db data structure.
struct __sol_db__ {
	BOOL Status;
	DBTYPE Type;
	union {
		// MySQL connector
		MYSQL mysql;
		// Postgres SQL connector
		PGconn *pgsql;
	} Connection;
	char *Host;
	char *User;
	char *Password;
	char *Name;
	int Port;
};

typedef struct __sol_db__ DB;

// @typ: struct __sol__
// SOL Module Structure.
struct __sol__ {

	// @sub: Node [SOL.Node]
	struct {
		unsigned int (*Length)(NODE *);
		unsigned int (*Rewind)(NODE **);
		unsigned int (*Forward)(NODE **);
		unsigned int (*Jump)(NODE **, int);
		unsigned int (*Walk)(NODE **, int);
		unsigned int (*Index)(NODE **);
		NODE *(*New)(const char *, const char *);
		void (*Drop)(NODE **);
		void (*Dump)(NODE *);
		void (*Push)(NODE **, const char *, const char *);
		void (*Append)(NODE **, NODE *);
		void (*Prepend)(NODE **, NODE *);
		void (*Unshift)(NODE **, const char *, const char *);

		// @sub: Get [SOL.Node.Get]
		struct {
			char *(*Attribute)(NODE *, const char *);
			char *(*Event)(NODE *, const char *);
		} Get;

		// @sub: Set [SOL.Node.Set]
		struct {
			void (*Value)(NODE **, const char *);
			void (*Attribute)(NODE **, const char *, const char *);
			void (*Event)(NODE **, const char *, const char *);
		} Set;

		// @sub: Add [SOL.Node.Add]
		struct {
			void (*Event)(NODE **, const char *, const char *);
		} Add;
	} Node;

	// @sub: String [SOL.String]
	struct {
		unsigned int (*SubstringCount)(const char *, const char *, ...);
		char *(*Replace)(const char *, const char *, const char *, ...);
		NODE *(*Split)(const char *, const char *, ...);
		char *(*Join)(NODE *, const char *, ...);
		char *(*LeftTrim)(const char *, const char);
		char *(*RightTrim)(const char *, const char);
		char *(*Trim)(const char *, const char);
		char *(*ToLowerCase)(const char *);
		char *(*ToUpperCase)(const char *);
		BOOL (*Compare)(const char *, const char *);
		char *(*IntegerToString)(int);
	} String;

	// @sub: String [SOL.Crypt]
	struct {
		char *(*MD5)(const char *, ...);
		char *(*SHA1)(const char *, ...);

		struct {
			char *(*Base64)(const char *, ...);
			char *(*Url)(const char *, ...);
			char *(*Hex)(unsigned int, ...);
		} Encode;

		struct {
			char *(*Base64)(const char *, ...);
			char *(*Url)(const char *, ...);
			int (*Hex)(const char *, ...);
		} Decode;

	} Crypt;

	// @sub: HTTP [SOL.HTTP]
	struct {
		// @sub: Querystring [SOL.HTTP.Querystring]
		struct {
			NODE *(*Parse)(const char *);
		} Querystring;

	} HTTP;

	// @sub: DB [SOL.DB]
	struct {

		void (*New)(DB *, DBTYPE);
		BOOL (*Status)(DB *);
		BOOL (*Connect)(DB *);

		// @sub: Set [SOL.DB.Set]
		struct {
			void (*Attribute)(DB *, DBATTR, const char *);
			void (*Type)(DB *, DBTYPE);
			void (*Host)(DB *, const char *);
			void (*Name)(DB *, const char *);
			void (*User)(DB *, const char *);
			void (*Password)(DB *, const char *);
			void (*Port)(DB *, int);
		} Set;

		/*
		void (*Shutdown)(void);

		// @sub: Get [SOL.DB.Get]
		struct {
			char *(*Host)(void);
			char *(*Name)(void);
			char *(*User)(void);
			char *(*Password)(void);
		} Get;

		BOOL (*Use)(const char *);
		BOOL (*Run)(NODE *);

		char *(*Merge)(const char *, NODE **);

		char *(*Create)(const char *, NODE **);
		char *(*Read)(NODE **);
		char *(*Update)(const char *, NODE **);
		char *(*Delete)(NODE **);
		*/

	} DB;

};

#endif

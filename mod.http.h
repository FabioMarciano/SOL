/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.crypt.h - SOL (Simple Object Library) crypt module header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MOD_HTTP_H
#define _SOL_MOD_HTTP_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
 
__SOF__

// @var	struct __sol_node__ HTTP_GET
// Holds the get data structure.
NODE *HTTP_GET;

// @var	struct __sol_node__ HTTP_POST
// Holds the posted data structure.
NODE *HTTP_POST;

// @var	struct __sol_node__ HTTP_POST
// Holds the file structure.
NODE *HTTP_FILES;

// @var	struct __sol_node__ HTTP_COOKIES
// Holds the cookies structure.
NODE *HTTP_COOKIES;

// @var	struct __sol_node__ HTTP_SESSION
// Holds the session structure.
NODE *HTTP_SESSION;

__EOF__

#endif

/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.h - SOL (Simple Object Library) header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_H
#define _SOL_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
#include "SOL/module.h"

// Start of File
__SOF__

// @var: struct __sol__ SOL
// Holds the main SOL object structure.
struct __sol__ SOL;

// @var: struct __sol_node__ ENV
// Holds the environment object structure.
NODE *ENV;

// @var: BOOL __sol_engine__
// Holds the SOL's engine status
BOOL __sol_engine__;

// @name	SOL_Init
// @type	function
// @param	none
// @return	void
void SOL_Init(void);

// @name	SOL_Quit
// @type	function
// @param	none
// @return	void
void SOL_Quit(void);

// End of File
__EOF__

#endif

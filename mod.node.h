/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.node.h - SOL (Simple Object Library) node module header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MOD_NODE_H
#define _SOL_MOD_NODE_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
 
__SOF__

// @name	__sol_module_node_new__
// @param	char node name
// @param	char node value
// @return	NODE pointer to new NODE
// Creates and return a pointer to a named/valued node.
extern inline NODE *__sol_module_node_new__(const char *, const char *);

// @name	__sol_module_node_length__
// @param	NODE pointer to pointer
// @return	unsigned int total of elements
// Counts the number of elements of an chainable structure.
extern inline unsigned int __sol_module_node_length__(NODE *);

// @name	__sol_module_node_rewind__
// @param	NODE pointer to pointer
// @return	unsigned int the number of steps back
// Rewinds the pointer cursor to first position.
extern inline unsigned int __sol_module_node_rewind__(NODE **);

// @name	__sol_module_node_forward__
// @param	void pointer to pointer
// @return	unsigned int the number of steps forward
// Forwards the pointer cursor to last position.
extern inline unsigned int __sol_module_node_forward__(NODE **);

// @name	__sol_module_node_index__
// @param	NODE pointer to chainable structure
// @return	unsigned int actual cursor's position at the chainable structure
// Gets the actual cursor's position at the chainable structure.
extern inline unsigned int __sol_module_node_index__(NODE **);

// @name	__sol_module_node_jump__
// @param	NODE pointer to pointer
// @param	int position
// @return	unsigned int the number of final position
// Jumps the cursor pointer to the passed position.
extern inline unsigned int __sol_module_node_jump__(NODE **, int);

// @name	__sol_module_node_walk__
// @param	NODE pointer to pointer
// @param	int offset
// @return	unsigned int the number of final position
// Move the cursor pointer "n" positions forward or backward.
extern inline unsigned int __sol_module_node_walk__(NODE **, int);

// @name	__sol_module_node_print_recursive__
// @param	NODE pointer to chainable structure
// @return	void
// Prints all name/value pairs in chainable structure.
extern inline void __sol_module_node_dump__(NODE *);

// @name	__sol_module_node_push__
// @param	void pointer to chainable structure
// @return	void
// Inserts a new node at the end of chainable structure.
extern inline void __sol_module_node_push__(NODE **, const char *, const char *);

// @name	__sol_module_node_unshift__
// @param	void pointer to chainable structure
// @return	void
// Inserts a new node at the start of chainable structure.
// Attention: this operation resets the node's cursor.
extern inline void __sol_module_node_unshift__(NODE **, const char *, const char *);

// @name	__sol_module_node_pop__
// @param	void pointer to chainable structure
// @return	NODE pointer to removed node
// Removes the last node of the chainable structure.
extern inline NODE *__sol_module_node_pop__(NODE **);

// @name	__sol_module_node_shift__
// @param	void pointer to chainable structure
// @return	NODE pointer to removed node
// Removes the first node of the chainable structure.
// Attention: this operation resets the node's cursor.
extern inline NODE *__sol_module_node_shift__(NODE **);

// @name	__sol_module_node_append__
// @param	void pointer to chainable structure
// @param	void pointer to chainable structure
// @return	void
// Inserts an existed node at the end of chainable structure.
// Attention: this operation resets the node's cursor.
extern inline void __sol_module_node_append__(NODE **, NODE *);

// @name	__sol_module_node_prepend__
// @param	void pointer to chainable structure
// @param	void pointer to chainable structure
// @return	void
// Inserts an existed node at the start of chainable structure.
// Attention: this operation resets the node's cursor.
extern inline void __sol_module_node_prepend__(NODE **, NODE *);

// @name	__sol_module_node_detach__
// @param	NODE pointer to chainable structure
// @return	void
// Detach a node from his structure.
extern inline void __sol_module_node_detach__(NODE **);

// @name	__sol_module_node_clear__
// @param	void pointer to chainable structure
// @return	void
// Clean up the node and his hierarchy freeling the memory alocated to him.
extern inline void __sol_module_node_clear__(NODE **);

// @name	__sol_module_node_drop__
// @param	NODE pointer to chainable structure
// @return	NODE pointer to NODE parentNode
// Detach and clean up the node.
extern inline void __sol_module_node_drop__(NODE **);

// @name	__sol_module_node_set_value__
// @param	NODE pointer to chainable structure
// @param	char new value to set
// @return	void
// Sets a new node value
extern inline void __sol_module_node_set_value__(NODE **, const char *);

// @name	__sol_module_node_set_attribute__
// @param	NODE pointer to chainable structure
// @param	char attribute name
// @param	char attribute value
// @return	void
// Sets a new node value
extern inline void __sol_module_node_set_attribute__(NODE **, const char *, const char *);

// @name	__sol_module_node_get_value__
// @param	NODE pointer to chainable structure
// @param	char attribute name
// @return	char value stored
// Returns the value by name
extern inline char *__sol_module_node_get_value__(NODE **, const char *);

__EOF__

#endif

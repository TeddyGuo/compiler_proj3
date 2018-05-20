#pragma once

#include <stdio.h>
/* maximum size of hash table */
#ifndef SIZE
#define SIZE 211
#endif

/* maximum size of tokens-identifiers */
#ifndef MAXTOKENLEN
#define MAXTOKENLEN 40
#endif

/* token types */
#ifndef UNDEF
#define UNDEF 0
#endif
#ifndef INT_TYPE
#define INT_TYPE 1
#endif
#ifndef REAL_TYPE
#define REAL_TYPE 2
#endif
#ifndef STR_TYPE
#define STR_TYPE 3
#endif
#ifndef LOGIC_TYPE
#define LOGIC_TYPE 4
#endif
#ifndef ARRAY_TYPE
#define ARRAY_TYPE 5
#endif
#ifndef FUNCTION_TYPE
#define FUNCTION_TYPE 6
#endif
/* new type for parser */
#ifndef CONST_INT_TYPE
#define CONST_INT_TYPE 7
#endif
#ifndef CONST_REAL_TYPE
#define CONST_REAL_TYPE 8
#endif
#ifndef CONST_STR_TYPE
#define CONST_STR_TYPE 9
#endif
#ifndef CONST_LOGIC_TYPE
#define CONST_LOGIC_TYPE 10
#endif

/* how parameter is passed */
#ifndef BY_VALUE
#define BY_VALUE 1
#endif
#ifndef BY_REFER
#define BY_REFER 2
#endif

/*
* Originally here, now it is in the symbols.c
* current scope
* int cur_scope = 0;
*/

/* parameter struct */
typedef struct Parameter{
	int par_type;
	char *param_name;
	// to store value
	int ival; double fval; char *sval; int bval; // boolean type
	int passing; // value or reference
	struct Parameter *next; // link to next one
	int counter;
}Param;

/* a linked list of references (lineno's) for each variable */
typedef struct Ref{ 
    int lineno;
    struct Ref *next;
    int type;
}RefList;

// struct that represents a list node
typedef struct list{
	char *st_name;
    int st_size;
    int scope;
    RefList *lines;
	// to store value and sometimes more information
	int st_ival; double st_fval; char *st_sval; int st_bval;
	// type
    int st_type;
	int inf_type; // for arrays (info type) and functions (return type)
	// array stuff
	int *i_vals; double *f_vals; char **s_vals; int *b_vals; // boolean type
	int array_size;
	// function parameters
	Param *parameters;
	int num_of_pars; // Meanwhile, it record the current position of the parameters
	// pointer to next item in the list
	struct list *next;
	char *func; // record which function the identifier in
	int counter; // record the counter of a variable in the current func
	short glob_flag; // record whether it is a global variable or not
}list_t;

/* the hash table */
static list_t **hash_table;

// Function Declarations
void create(); // initialize hash table
unsigned int hash(char *key); // hash function for insert
void insert(char *name, int len, int type, int lineno, char* func); // insert entry plus func
list_t *lookup(char *name); // search for entry
list_t *lookup_scope(char *name, int scope); // search for entry in scope
void hide_scope(); // hide the current scope
void incr_scope(); // go to next scope
void dump(FILE *of); // dump file

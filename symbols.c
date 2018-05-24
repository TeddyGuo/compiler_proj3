// source: https://steemit.com/programming/@drifter1/writing-a-simple-compiler-on-my-own-using-symbol-tables-in-the-lexer
// This symbol table was created by drifter1, and I change something to fit this project
/*

April 30, 2018
Increase more info when write the file "dump.out"
For example, constant_int, constant_real, and so on.

May 1, 2018
Change the format when write info into dump.out line 134-140

May 24, 2018
I found func variable in proj3 is trash since it is very useless.
*/
#include "symbols.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* current scope */
int cur_scope = 0;

void create()
{
	int i; 
	hash_table = malloc(SIZE * sizeof(list_t*));
	for(i = 0; i < SIZE; i++) hash_table[i] = NULL;
}

unsigned int hash(char *key)
{
	unsigned int hashval = 0;
	for(;*key!='\0';key++) hashval += *key;
	hashval += key[0] % 11 + (key[0] << 3) - key[0];
	return hashval % SIZE;
}

void insert(char *name, int len, int type, int lineno)
{
	unsigned int hashval = hash(name); // hash function used
	list_t *l = hash_table[hashval];
	
	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
	
	/* variable not yet in table */
	if (l == NULL){
		l = (list_t*) malloc(sizeof(list_t));
		l->st_name = strdup(name);  
		/* add to hashtable */
		l->st_type = type;
		l->scope = cur_scope;
		l->lines = (RefList*) malloc(sizeof(RefList));
		l->lines->lineno = lineno;
		l->lines->next = NULL;
		l->next = hash_table[hashval];
		hash_table[hashval] = l; 
		// printf("Inserted %s for the first time with linenumber %d!\n", name, lineno); // error checking
	}
	/* found in table, so just add line number */
	else{
		l->scope = cur_scope;
		RefList *t = l->lines;
		while (t->next != NULL) t = t->next;
		/* add linenumber to reference list */
		t->next = (RefList*) malloc(sizeof(RefList));
		t->next->lineno = lineno;
		t->next->next = NULL;
		// printf("Found %s again at line %d!\n", name, lineno);
	}
}

list_t *lookup(char *name)
{ /* return symbol if found or NULL if not found */
    unsigned int hashval = hash(name);
    list_t *l = hash_table[hashval];
    while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
    return l; // NULL is not found
}

list_t *lookup_scope(char *name, int scope)
{ /* return symbol if found or NULL if not found */
    unsigned int hashval = hash(name);
    list_t *l = hash_table[hashval];
    while ((l != NULL) && (strcmp(name,l->st_name) != 0) && (scope != l->scope)) l = l->next;
    return l; // NULL is not found
}

void hide_scope()
{ /* hide the current scope */
	if(cur_scope > 0) cur_scope--;
}
void incr_scope()
{ /* go to next scope */
	cur_scope++;
}

/* print to stdout by default */ 
void dump(FILE * of)
{  
  int i; int count; // record whether first line prints or not.
  
  fprintf(of,"------------ --------------------------- ---------------------- \n");
  fprintf(of,"Name         Type                        Line Numbers           \n");
  fprintf(of,"------------ --------------------------- ---------------------- \n");

  for (i=0; i < SIZE; ++i){ 
	if (hash_table[i] != NULL){ 
		list_t *l = hash_table[i];
		while (l != NULL){ 
			RefList *t = l->lines;
			if (l->st_name != NULL)
			{
				fprintf(of,"%-12s ",l->st_name);
				printf("%s\n", l->st_name); // print out all the names in the symbol table
			}
			if (l->st_type == INT_TYPE) fprintf(of,"%-7s","int");
			else if (l->st_type == REAL_TYPE) fprintf(of,"%-7s","real");
			else if (l->st_type == STR_TYPE) fprintf(of,"%-7s","string");
			else if (l->st_type == LOGIC_TYPE)	fprintf(of,"%-7s","bool");
			else if (l->st_type == CONST_INT_TYPE) fprintf(of, "%-7s", "const_int"); // constant_int_type
			else if (l->st_type == CONST_REAL_TYPE) fprintf(of, "%-7s", "const_real"); // constant_real_type
			else if (l->st_type == CONST_STR_TYPE) fprintf(of, "%-7s", "const_string"); // constant_string_type
			else if (l->st_type == CONST_LOGIC_TYPE) fprintf(of, "%-7s", "const_bool"); // const_logic_type
			else if (l->st_type == ARRAY_TYPE){
				fprintf(of,"array of ");
				if (l->inf_type == INT_TYPE) 		   fprintf(of,"%-7s","int");
				else if (l->inf_type  == REAL_TYPE)    fprintf(of,"%-7s","real");
				else if (l->inf_type  == STR_TYPE) 	   fprintf(of,"%-7s","string");
				else if (l->inf_type == LOGIC_TYPE)	   fprintf(of,"%-7s","bool");
				else fprintf(of,"%-7s","undef");
			}
			else if (l->st_type == FUNCTION_TYPE){
				fprintf(of,"%-7s","function returns ");
				if (l->inf_type == INT_TYPE) 		   fprintf(of,"%-7s","int");
				else if (l->inf_type  == REAL_TYPE)    fprintf(of,"%-7s","real");
				else if (l->inf_type  == STR_TYPE) 	   fprintf(of,"%-7s","string");
				else if (l->inf_type == LOGIC_TYPE)	   fprintf(of,"-7%s","bool");
				else fprintf(of,"%-7s","undef");
			}
			else fprintf(of,"%-7s","undef"); // if UNDEF or 0

			count = 0;
			while (t != NULL){
				if (count == 0)
				{
				if (l->st_type == INT_TYPE || l->st_type == REAL_TYPE || l->st_type == STR_TYPE || l->st_type == LOGIC_TYPE || l->st_type == UNDEF)
					fprintf(of,"%23d ", t->lineno);
				else if (l->st_type == CONST_INT_TYPE || l->st_type == CONST_REAL_TYPE || l->st_type == CONST_STR_TYPE || l->st_type == CONST_LOGIC_TYPE)
					fprintf(of,"%17d", t->lineno);
				else if (l->st_type == ARRAY_TYPE)
					fprintf(of,"%14d", t->lineno);
				else if (l->st_type == FUNCTION_TYPE)
					fprintf(of,"%6d", t->lineno);
				}
				else
					fprintf(of,"%3d", t->lineno);
				count++;
				t = t->next;
			}
			fprintf(of,"\n");
			l = l->next;
		}
    }
  }
}

int stoi(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
    {
      if (*str == '-')
        puiss = puiss * -1;
      str++;
    }
  while ((*str >= '0') && (*str <= '9'))
    {
      result = (result * 10) + ((*str) - '0');
      str++;
    }
  return (result * puiss);
}

char* itos(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}
/*CS2014 Lab9
 
 Name: David Byrne
 Student ID: 09068783
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list * list_new();

int list_is_empty(struct list * this);

void list_pushback(struct list * this, int item);

void list_move_to_start(struct list * this);

void list_move_to_next(struct list * this);

int list_at_end(struct list * this);

int list_get_current(struct list * this);

void list_set_current(struct list * this, int item);

void list_delete_current(struct list * this);

void list_popback(struct list * this);

int string_length(char str[]);

void clearTheString(char str[]);
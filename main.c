/*CS2014 Lab9
 
 Name: David Byrne
 Student ID: 09068783
 
 */

#include "main.h"

struct list_element {
	int data;
	struct list_element * next;
	struct list_element * prev;
};

struct list {
	struct list_element * head;
	struct list_element * tail;
	struct list_element * iterator;
};

/*
 * Create a new list and set its attributes to NULL.
 */
struct list * list_new(){
	struct list * result;
	result = malloc(sizeof(struct list));
	result->head = NULL;
	result->tail = NULL;
	result->iterator = NULL;
	return result;
}

/*
 * Check if it is empty based on the head attribute, return 1 if empty otherwise 0.
 */
int list_is_empty(struct list * this){
	if(this->head == NULL){
		return 1;
	}
	return 0;
}

/*
 * Add a element to the list. Check if it is empty, if it is add a new head
 * and set prev and next to NULL otherwise just add it to the tail.
 */
void list_pushback(struct list * this, int item){
	struct list_element * new;
	new = malloc(sizeof(struct list_element));
	
	new->data = item;
	if(list_is_empty(this) == 1){
		this->head = new;
		this->tail = new;
		new->next = NULL;
		new->prev = NULL;
		this->iterator = new;
	}else{
		this->tail->next = new;
		new->prev = this->tail;
		this->tail = new;
	}
}

/*
 * Move the iterator(pointer) to the start.
 */
void list_move_to_start(struct list * this){
	this->iterator = this->head;
}

/*
 * Move the iterator to the next element in the list.
 */
void list_move_to_next(struct list * this){
	if(list_at_end(this) != 1){
		this->iterator = this->iterator->next;
	}
}

/*
 * Return 1 if the pointer is at the end of the list otherwise 0.
 */
int list_at_end(struct list * this){
	if(list_is_empty(this) == 1 || this->iterator == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*
 * Return integer value the iterator is pointing at.
 */
int list_get_current(struct list * this){
	return this->iterator->data;
}

/*
 * Set the value of the element the iterator is pointing at.
 */
void list_set_current(struct list * this, int item){
	this->iterator->data = item;
}

/*
 * Delete the element the iterator is pointing at.
 */
void list_delete_current(struct list * this){
	if(this->iterator == this->head){
		this->head = this->head->next;
		this->head->next->prev = NULL;
	}else if(this->iterator == this->tail){
		this->tail->prev->next = NULL;
		this->tail = this->tail->prev;
	}else if(this->iterator == this->head && this->iterator == this->tail){
		this->tail = NULL;
		this->head = NULL;
	}else{
		this->iterator->prev->next = this->iterator->next;
		this->iterator->next->prev = this->iterator->prev;
	}
}

/*
 * Pop the last element off the list.
 */
void list_popback(struct list * this){
	if(list_is_empty(this) != 1){
		if(this->tail->prev == NULL){
			this->tail = NULL;
			this->head = NULL;
		}else{
			this->tail = this->tail->prev;
			//this->tail->prev->next = NULL;
			this->tail->next = NULL;
		}
	}
}

int main () {
	
	int choice = -1;
	char text[20];
	struct list * li = list_new();
	
	do {
		clearTheString(text);
		printf("Menu:\n");
		printf("(1) Add an item to the double linked list.\n");
		printf("(2) Push an item off the double linked list.\n");
		printf("(3) Move the pointer to the start.\n");
		printf("(4) Set the link the pointer is on to a particular value.\n");
		printf("(5) Delete the link the pointer is on\n");
		printf("(6) Get the current value of the link the pointer is on.\n");
		printf("(7) List out all the values in the double linked list.\n");
		printf("(8) Move the pointer to the link.\n");
		printf("(9) Quit.\n");
		scanf("%d", &choice);
		printf("\n");
		
		switch (choice) {
			case 1:
				clearTheString(text);
				int theItem = 0;
				printf("Please enter the value you wish to add:");
				scanf("%d", &theItem);
				printf("\n");
				list_pushback(li, theItem);
				break;
				
			case 2:
				printf("You have pushed an item off the list.\n");
				list_popback(li);
				break;
				
			case 3:
				printf("You have moved the pointer to the start.\n");
				list_move_to_start(li);
				break;
				
			case 4:
				clearTheString(text);
				int setItem = 0;
				printf("Please enter the value you wish to enter:");
				scanf("%d", &setItem);
				printf("\n");
				list_set_current(li, setItem);
				break;
				
			case 5:
				printf("You have deleted the element the pointer is at.\n");
				list_delete_current(li);
				break;
				
			case 6:
				printf("The pointer is currently at:%d\n", list_get_current(li));
				break;
				
			case 7:
				if(list_is_empty(li) == 1){
					printf("This list is empty.\n");
				}else{
					printf("The list contains the following values:\n");
					list_move_to_start(li);
					while(list_at_end(li) != 1){
						printf("%d\n", list_get_current(li));
						list_move_to_next(li);
					}
				}
				break;
				
			case 8:
				printf("You have the pointer to the next link.\n");
				list_move_to_next(li);
				
			case 9:
				printf("Program quitting.\n");
				break;
				
			default:
				printf("Not a valid menu choice.\n");
				break;
				
		}
	} while (choice != 9);
	
    return 0;
}

/*
 * string_length is used to calculate how many characters are in a string
 */
int string_length(char str[]){
	int count=0;
	while(str[count] !='\0'){
		count++;
	}
	return count-1;
}

/*
 * clearString removes all previous character from the previous string by
 * inserting the null terminator '\0'
 */
void clearTheString(char str[]){
	int i=0;
	int length = string_length(str);
	for (i=0; i<=length; i++) {
		str[i]='\0';
	}
}

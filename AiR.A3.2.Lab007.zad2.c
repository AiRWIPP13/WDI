#include <malloc.h>

struct ListNode {
int key;
ListNode *next;	
};

ListNode *add(ListNode *first, int key) {
            if ( first == NULL) {
ListNode *n = (ListNode *)malloc(siezof(ListNode));
n->key = key;	
n->next = first;
	return n;
 } 
if ( first->key > key) {
ListNode *n = (ListNode *)malloc(siezof(ListNode));
n->key = key;
	n->next = first;
	return n;
}
first->next = add(first->next, key);
	return n;
}

ListNode *remove(ListNode *first, int key) {
	if (first == NULL) {
		return first;
}
if (first->key == key) {
	ListNote *next = first->next;
	free(first);
return next;
}
first->next = remove(first->next, key);
return first;
}

int main() {

	ListNode *first = NULL;
	ListNode *x = (ListNode *)malloc(siezof(ListNode));
	
	first = add(first, 5); 
first = add(first, 1);
first = add(first, 8); 
ListNode *current = first;
while (current != NULL) {
	printf(“%d\n”, current->key);
	current = current->key;
}

first = remove(first,5);
current = first;
while (current != NULL) {
	printf(“%d\n”, current->key);
	current = current->key;
}

free(x);

}

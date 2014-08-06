#include "ll_cnode.h" /* File: ll_create.cpp */
// Create a ll_cnode and initialize its data
ll_cnode* ll_create(char c) {
    ll_cnode* p = new ll_cnode; p->data = c; p->next = NULL; return p;
}

// Create a linked list of ll_cnodes with the contents of a char array
ll_cnode* ll_create(const char s[ ]) {
    if (s[0] == NULL_CHAR) // Empty linked list due to empty C string
        return NULL;
    
    ll_cnode* head = new ll_cnode; // Special case with the head
    head->data = s[0]; // Initialize the data pointed by head

    ll_cnode* p = head; // p is the working pointer
    for(int j = 1; s[j] != NULL_CHAR; ++j)
    {
        p->next = new ll_cnode; // Link the current ll_cnode to the new ll_cnode
        p = p->next; // p now points to the new ll_cnode
        p->data = s[j]; // Initialize the ll_cnode data
    }
    p->next = NULL; // The last ll_cnode should point to NOTHING
    return head; // The WHOLE linked list can be accessed from the head
}

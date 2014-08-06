#include "ll_cnode.h" /* File: ll_delete_all.cpp */

// To delete the WHOLE linked list, given its head.
void ll_delete_all(ll_cnode*& head)
{
    if (head == NULL)          // An empty list; nothing to delete
        return;
    
    ll_delete_all(head->next); // STEP 1: First delete the remaining nodes

    // For debugging: this shows you what are deleting
    cout << "deleting " << head->data << endl;
    delete head;               // STEP 2: Then delete the current nodes

    head = NULL;               // STEP 3: To play safe, reset head to NULL
}

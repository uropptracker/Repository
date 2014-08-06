/*
 * cll.cpp
 *
 */

#include <iostream>
#include "cll.h"
using namespace std;


/*
 * Initialize the circular linked list as an empty list.
 *
 */
void cll_init(CLL& cll)
{
    cll.head = NULL;
}


/*
 * Remove all the nodes of a circular linked list and reset its head to NULL.
 *
 */
void cll_delete_all(CLL& cll)
{
    if (cll.head == NULL) // Special case: Empty CLL
        return;

    cll_node* current = cll.head;

    do
    {
        cll_node* next = current->next;
        delete current;
        current = next;
    } while (current != cll.head);

    cll.head = NULL;
}



/*
 * Print all the values in the nodes of a circular linked list separated by a space.
 *
 */
void cll_print(const CLL& cll)
{
	for (const cll_node* p = cll.head; cll.head != NULL && p->next != cll.head; p = p->next)
		cout << p->value << " ";
    /*const cll_node* p = cll.head;
    if (cll.head != NULL)
    {
        do
        {
            cout << p->value << " ";
            p = p->next;
        }
        while (p != cll.head);
    }*/
}



/*
 * Append a new node to the tail of a circular linked list.
 *
 */
void cll_append(CLL& cll, int v)
{
    if (cll.head == NULL)
    {
        cll.head = new cll_node;
        cll.head->value = v;
        cll.head->next = cll.head;
    }
    else
    {
        cll_node* current = cll.head;
        do
            current = current->next;
        while (current->next != cll.head);

        current->next = new cll_node;
        current->next->value = v;
        current->next->next = cll.head;
    }
}


/*
 * Insert a new node with value v into a circular linked list after its node
 * with a value 'after_value'.
 * Return: true if succeed, otherwise false (when after_value is not found).
 */
bool cll_insert(CLL& cll, int v, int after_value)
{
    //Add your code here
    cll_node* new_node = new cll_node;
    cll_node* current = cll.head;


	while (current->next != cll.head && current->value != after_value)
		current = current->next;

	if (current != cll.head || current->value == after_value)
	{
		new_node->value = v;
		new_node->next = current->next;
		current->next = new_node;
		return true;
	}
    return false;


}


/*
 * Delete the node with value v in the circular linked list.
 * Return: true if succeed, otherwise false (when the value v is not found.)
 */
bool cll_delete(CLL& cll, int v)
{
   //Add your code here
    cll_node* prev = new cll_node;
    cll_node* current = cll.head;

    do
    {
        prev = current;
        current = current->next;
    } while (current->value != v && current != cll.head);

    if (current->value == v)
    {
        if (current == cll.head)
        {
            prev->next = cll.head->next;
            cll.head = cll.head->next;
        }
        else
            prev->next = current->next;
        delete current;
        return true;
    }
    return false;
}


// NAME: Yeung Pak Shing
// ID: 20116568
// EMAIL: psyeungaa@connect.ust.hk
// LAB SECTION:LA2

#include <iostream>
#include "sll.h"
using namespace std;



/*
 * To generate a sorted linked list with integers from start to end
 * with a step-size of step.
 *
 * Note: You may assume that step is always +ve.
 */
sll_node* sll_create(int start, int end, int step)
{
	sll_node* head = new sll_node;
	head->value = start;

	sll_node* node = head;
	for (int i=start+step; i <= end; i+=step)
	{
		node->next = new sll_node;
		node = node->next;
		node->value = i;
	}

	node->next = NULL;
	return head;
}


/*
 * To insert a sll_node into the sorted linked list with an integer,
 * value.
 *
 * Note: The new node may be the first node in the resulting SLL.
 */
void sll_insert(sll_node*& head, int value)
{
    // TODO #2
    // ADD YOUR CODE HERE
	sll_node* prev = new sll_node;
	sll_node* current = head;

	sll_node* new_node = new sll_node;
	new_node->value = value;
	new_node->next = new sll_node;
	new_node->next = NULL;

	while (current != NULL && value >= current->value )	//Short-circuit of condition
	{
		prev = current;
		current = current->next;
	}
	//Special case: head has to be changed
	if (current == head)
	{
		new_node->next = head;
		head = new_node;
	}
	//Change at the other node
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}
}


/*
 * To remove any duplicate values in the sorted linked list.
 *
 * Note: If the first value has duplicates, the first node will not
 *       be removed so that the head will not change.
 */
void sll_remove_duplicates(sll_node* head)
{
    // TODO #3
    // ADD YOUR CODE HERE
	if (head == NULL)		//EMPTY case just return
		return;

	sll_node* begin_node = head;

	//Beginning node
	while (begin_node->next != NULL)
	{
		sll_node* scanner = begin_node->next;

		while (scanner != NULL && scanner->value != begin_node->value)
			scanner = scanner->next;

		if (scanner != NULL && scanner->value == begin_node->value)
		{
			begin_node->next = scanner->next;
			sll_delete(scanner);
			continue;		//Prevent shifting of the linked list
		}
		begin_node = begin_node->next;
	}
}


/*
 * To modify the first given SLL so that it contains all the distinct nodes
 * of the given 2 SLLs.
 *
 * Note: The 2nd list headed by p2 should NOT be modified. Any new nodes of
 *       list p1 should be dynamically created.
 */
void sll_union(sll_node*& p1, const sll_node* p2)
{
    // TODO #4
    // ADD YOUR CODE HERE
	sll_remove_duplicates(p1);

	//Special case: p1 is empty
	if (p1 == NULL)
	{
		p1 = new sll_node;
		p1->value = p2->value;
		sll_node* temp = p1;
		while (p2->next != NULL)
		{
			p2 = p2->next;
			temp->next = new sll_node;
			temp = temp->next;
			temp->value = p2->value;
		}
		temp->next = NULL;
		return;
	}

	while (p2 != NULL)
	{
		sll_node* modifying_node = p1;
		while (modifying_node != NULL)
		{
			sll_node* new_node = new sll_node;
			new_node->value = p2->value;
			new_node->next = new sll_node;
			new_node->next = NULL;

			if (modifying_node->value == p2->value)
				break;
			//Either end or at the middle of the number
			else
			{
				if (modifying_node->next == NULL)		//Last case
					modifying_node->next = new_node;

				else if (p2->value > modifying_node->value && p2->value < modifying_node->next->value)	//Middle case
				{
					new_node->next = modifying_node->next;
					modifying_node->next = new_node;
				}
				else if (p2->value < modifying_node->value)		//Head case
				{
					new_node->next = modifying_node;
					p1 = new_node;
					continue;		//Prevent potential shifting of the linked list
				}
			}
			modifying_node = modifying_node->next;
		}
		p2 = p2->next;
	}
}


/*
 * To modify the first given SLL so that it contains only the common nodes
 * between the given 2 SLLs.
 *
 * Note: The 2nd list headed by p2 should NOT be modified.
 */
void sll_intersection(sll_node*& p1, const sll_node* p2)
{
    // TODO #5
    // ADD YOUR CODE HERE
	sll_remove_duplicates(p1);

	sll_node* current = p1;
	sll_node* prev = current;

	while (current != NULL)
	{
		bool added = false;

		sll_node* temp = current;
		const sll_node* check_node = p2;

		while (check_node != NULL)
		{
			if (current->value == check_node->value)	//If find the intersection
			{
				if (current->next == NULL) return;		//Quit the whole function if the intersection is the last one
				else break;								//Just break if it is not the last one
			}
			else if (check_node->next == NULL)
			{
				if (temp->value == p1->value)			//Special case:Head
				{
					p1 = p1->next;						//
					current = current->next;			// Both shift the linked list
					added = true;						//Added becomes true to prevent shifting at the last
				}
				else
				{
					prev->next = current->next;			//Connect the gap (gap between the node will be deleted)
					current = p1;						//Update the linked list
				}
				sll_delete(temp);						//Delete!

			}
			check_node = check_node->next;
		}
		prev = current;
		if (added == false && current->next != NULL)
		current = current->next;
	}
}

/*
 * To print the sorted linked list in the following format:
 * e.g., if the SLL contains the integers 3, 8, 9, then output
 *       (3)->(8)->(9)
 */
void sll_print(const sll_node* p)
{
    if (p == NULL)      // Base case: empty SLL
        return;

    cout << "(" << p->value << ")"; // Print the current node

    if (p->next != NULL) // This is NOT the last node
    {
        cout << "->";
        sll_print(p->next); // Recursive step!
    }
    else                // This IS the last node
        cout << endl;
}


/*
 * To delete one SLL node but print out its value first.
 */
void sll_delete(sll_node* p)
{
    cout << "D: (" << p->value << ")" << endl;
    delete p;
}


/*
 * To delete all the nodes of an SLL, starting from the last node.
 */
void sll_delete_all(sll_node*& head)
{
    if (head == NULL)
        return;
    else
    {
        sll_delete_all(head->next);
        sll_delete(head);
        head = NULL;
    }
}

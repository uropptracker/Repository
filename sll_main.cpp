/*
 *
 ************** YOU DO NOT NEED TO SUBMIT THIS FILE **************
 **** THE MAIN FUNCTION WILL BE MODIFIED TO TEST YOUR PROGRAM ****
 *
 */

#include <iostream>
#include "sll.h"
using namespace std;


int main(void)
{
    sll_node* m = NULL;
    sll_node* n = NULL;
    sll_node* p = NULL;
    sll_node* q = NULL;

    sll_insert(p, 3);
    sll_insert(p, 5);
    q = sll_create(3, 8, 1);
    cout << endl << "Sorted linked list p: " << endl;
    sll_print(p);
    cout << endl << "Sorted linked list q: " << endl;
    sll_print(q);


    cout << endl << "Union of p and q, also q and p:" << endl;
    sll_union(p, q);
    sll_union(q, p);
    cout << endl << "Sorted linked list m after union: " << endl;
    sll_print(m);
    cout << endl << "Sorted linked list n after union: " << endl;
    sll_print(n);
    cout << endl << "Sorted linked list p after union: " << endl;
    sll_print(p);
    cout << endl << "Sorted linked list q after union: " << endl;
    sll_print(q);

    cout << endl << "Intersection m and n:" << endl;
    sll_intersection(m, n);
    cout << endl << "Sorted linked list m after intersection: " << endl;
    sll_print(m);
    cout << endl << "Sorted linked list n after intersection: " << endl;
    sll_print(n);
    cout << endl << "Insert into m:" << endl;
    sll_insert(m, 3);
    sll_insert(m, 3);
    sll_insert(m, 4);
    sll_insert(m, 2);
    sll_insert(m, 0);
    sll_insert(m, 4);
    sll_insert(m, 2);
    sll_insert(m, 4);
    sll_insert(m, 2);
    sll_insert(m, 9);
    sll_print(m);

    cout << endl << "Union of m and q:" << endl;
    sll_union(m, q);
    cout << endl << "Sorted linked list m after union: " << endl;
    sll_print(m);
    cout << endl << "Sorted linked list q after union: " << endl;
    sll_print(q);

    cout << endl << "Intersection n and p:" << endl;
    sll_intersection(n, p);
    cout << endl << "Sorted linked list n after intersection: " << endl;
    sll_print(n);
    cout << endl << "Sorted linked list p after intersection: " << endl;
    sll_print(p);

    cout << endl << "Insert into n:" << endl;
    sll_insert(n, 3);
    sll_insert(n, 3);
    sll_insert(n, 4);
    sll_insert(n, 2);
    sll_insert(n, 0);
    sll_insert(n, 6);
    sll_insert(n, 9);
    sll_insert(n, 9);
    sll_print(n);

    cout << endl << "Intersection n and p:" << endl;
    sll_intersection(n, p);
    cout << endl << "Sorted linked list n after intersection: " << endl;
    sll_print(n);
    cout << endl << "Sorted linked list p after intersection: " << endl;
    sll_print(p);

    cout << endl << "Delete p:" << endl;
    sll_delete_all(p);
    cout << endl << "Delete q:" << endl;
    sll_delete_all(q);
    cout << endl << "Delete m:" << endl;
    sll_delete_all(m);
    cout << endl << "Delete n:" << endl;
    sll_delete_all(n);

    if (p == NULL && q == NULL && n == NULL && m == NULL)
        cout << endl << "OK! All lists are deleted." << endl;

    return 0;
}

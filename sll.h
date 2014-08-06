struct sll_node
{
    int value;        // An integer stored in the node
    sll_node* next;   // A pointer to the next node in the sorted list
};


// Functions to implement
void sll_insert(sll_node*& head, int value);
void sll_remove_duplicates(sll_node* head);
sll_node* sll_create(int start, int end, int step);
void sll_union(sll_node*& p1, const sll_node* p2);
void sll_intersection(sll_node*& p1, const sll_node* p2);

// The following functions are already given
void sll_print(const sll_node* p);
void sll_delete(sll_node* p);
void sll_delete_all(sll_node*& head);

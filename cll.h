struct cll_node
{
	int value;
	cll_node* next;
};

struct CLL
{
	cll_node* head;
};

void cll_init(CLL& loop);
void cll_delete_all(CLL& loop);

void cll_print(const CLL& loop);
void cll_append(CLL& loop, int v);
bool cll_insert(CLL& loop, int v, int after_value);
bool cll_delete(CLL& loop, int v);

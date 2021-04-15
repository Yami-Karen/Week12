#include <iostream>
#include <cassert>
using namespace std;
struct Linkedlist
{
	const char* data;
	Linkedlist* head;
	Linkedlist* tail;
	~Linkedlist()
	{
		delete[]data;
		delete[]head;
		delete[]tail;
	}
	void init(const char* c)
	{
		data = c;
		head = NULL;
		tail = NULL;
	}
	Linkedlist* createNode(const char* c)
	{
		Linkedlist* tmp = new Linkedlist;
		tmp->data = c;
		tmp->head = NULL;
		tmp->tail = NULL;
		return tmp;
	}
	Linkedlist* addFirst(const char* c)
	{
		assert(this != NULL);
		Linkedlist* tmp = createNode(c);
		tmp->tail = this;
		this->head = tmp;
		return tmp;
	}
	void print()
	{
		assert(this != NULL);
		Linkedlist* read = this;
		while (read != NULL)
		{
			cout << read->data << " ";
			read = read->tail;
		}
		cout << "\n------------------\n";
	}
	void addLast(const char* c)
	{
		assert(this != NULL);
		Linkedlist* tmp = createNode(c);
		Linkedlist* read = this;
		while (read->tail != NULL) read = read->tail;
		read->tail = tmp;
		tmp->head = read;
	}
	Linkedlist* removeFirst()
	{
		assert(this != NULL);
		assert(this != NULL);
		this->tail->head = NULL;
		return this->tail;
	}
	void removeLast()
	{
		assert(this != NULL);
		Linkedlist* read = this;
		while (read->tail->tail != NULL) read = read->tail;
		read->tail = NULL;
	}
	void insertAfter(Linkedlist* p, const char* c)
	{
		assert(this != NULL);
		assert(p == NULL);
		if (p->tail == NULL)  addLast(c);
		else
		{
			Linkedlist* tmp = createNode(c);
			p->tail->head = tmp;
			tmp->tail = p->tail;
			tmp->head = p;
			p->tail = tmp;
		}
	}
	Linkedlist* removeNode(Linkedlist* p)
	{
		assert(this != NULL);
		assert(p != NULL);
		if (this == p) { removeFirst(); return this; }
		else if (p->tail == NULL) { removeLast(); return this; }
		else
		{
			Linkedlist* i = p->head;
			Linkedlist* j = p->tail;
			i->tail = j;
			j->head = i;
			return this;
		}
	}
};
int main()
{
	Linkedlist* f = new Linkedlist;
	f->init("Heavy");
	f = f->addFirst("Metal");
	f->addLast("Burst");
	f->print();
	f = f->removeFirst();
	f->print();
	f->removeLast();
	f->print();
	f->insertAfter(f, "Lina");
	f->insertAfter(f, "K");
	f->print();
	f = f->removeNode(f->tail);
	f->print();
	return 0;
}
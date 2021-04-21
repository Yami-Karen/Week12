#include <iostream>
#include <cassert>
using namespace std;
struct Linkedlist
{
	const char* data;
	Linkedlist* head;
	Linkedlist* tail;
	Linkedlist(const char* string)
	{
		data = string;
		this->head = NULL;
		this->tail = NULL;
	}
	~Linkedlist()
	{
		delete[]data;
		delete[]head;
		delete[]tail;
	}
	Linkedlist* addFirst(const char* c)
	{
		Linkedlist* tmp = new Linkedlist(c);
		tmp->tail = this;
		this->head = tmp;
		return tmp;
	}
	void addLast(const char* c)
	{
		Linkedlist* tmp = new Linkedlist(c);
		Linkedlist* read = this;
		while (read->tail != NULL) read = read->tail;
		read->tail = tmp;
		tmp->head = read;
	}
	Linkedlist* removeFirst()
	{
		this->tail->head = NULL;
		return this->tail;
	}
	void removeLast()
	{
		Linkedlist* read = this;
		while (read->tail->tail != NULL) read = read->tail;
		read->tail = NULL;
	}
	void insertAfter(Linkedlist* p, const char* c)
	{
		assert(p != NULL);
		if (p->tail == NULL)  addLast(c);
		else
		{
			Linkedlist* tmp = new Linkedlist(c);
			p->tail->head = tmp;
			tmp->tail = p->tail;
			tmp->head = p;
			p->tail = tmp;
		}
	}
	Linkedlist* removeNode(Linkedlist* p)
	{
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
};
int main()
{
	Linkedlist* f = new Linkedlist("Heavy");
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

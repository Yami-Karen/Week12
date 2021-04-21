#include <iostream>
using namespace std;
struct Linkedlist
{
	const char* data;
	Linkedlist* next;
	Linkedlist(const char* string)
	{
		data = string;
		next = NULL;
	}
	~Linkedlist()
	{
		delete[]data;
		delete[]next;
	}
	Linkedlist* addFirst(const char* c)
	{
		Linkedlist* tmp = new Linkedlist(c);
		tmp->next = this;
		return tmp;
	}
	void addLast(const char* c)
	{
		Linkedlist* tmp = new Linkedlist(c);
		Linkedlist* read = this;
		while (read->next != NULL) read = read->next;
		read->next = tmp;
	}
	void print()
	{
		Linkedlist* read = this;
		while (read != NULL)
		{
			cout << read->data << " ";
			read = read->next;
		}
		cout << "\n--------------\n";
	}
	Linkedlist* removeFirst()
	{
		return this->next;
	}
	void removeLast()
	{
		Linkedlist* read = this;
		while (read->next->next != NULL) read = read->next;
		read->next = NULL;
	}
	void insertAfter(Linkedlist* p, const char* c)
	{
		Linkedlist* tmp = new Linkedlist(c);
		if (p->next == NULL) p->next = tmp;
		else
		{
			tmp->next = p->next;
			p->next = tmp;
		}
	}
	Linkedlist* removeNode(Linkedlist* p)
	{
		if (this == p) return this->next;
		else if (p->next == NULL) { removeLast(); return this; }
		else
		{
			Linkedlist* read = this;
			while (read->next != p) read = read->next;
			read->next = p->next;
			return this;
		}
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
	f->print();
	f->insertAfter(f, "K");
	f = f->removeNode(f->next);
	f->print();
	return 0;
}

#include "hashmap.h"

using namespace CODE;

Hashmap::Hashmap()
{
	length = capacity;
	kcount = 0; 
	ecount = 0;
	elements.resize(length);
}

Hashmap::Hashmap(KEY k, VALUE v)
{
	Hashmap();
	Element* e = new Element;
	int idx = GetHashIndex(*e);
	elements[idx] = e;
}

Element* Hashmap::InitElement(KEY k, VALUE v)
{
	Element* e = new Element;
	e->key = k;
	e->value = v;
	e->next = new struct Element;
	return e;
}

int Hashmap::GetHashIndex(Element e)
{
	// hash function
	return (e.key * 11 + (int)e.value.length() % 11) % length;
}

int Hashmap::AddElement(KEY k, VALUE v)
{
	Element* e = InitElement(k, v);
	int idx = GetHashIndex(*e);
	if(elements[idx] == NULL) // the element is empty
	{
		elements[idx] = e;
		kcount++;
		ecount++;
		return idx;
	}
	// find the last location of the linked list
	Element* enext = elements[idx];
	while (enext->next != NULL && enext->key != e->key)
		enext = enext->next;
	if (enext->key == e->key)
	{
		enext->value = v;
	}
	else
	{
		enext->next = e;
		ecount++;
	}
	return idx;
}

int Hashmap::RemoveElement(KEY k, VALUE v)
{
	Element* e = InitElement(k,v);
	int idx = GetHashIndex(*e);
	if(elements[idx] == NULL) 
		return -1; // not found
	if (elements[idx]->key == k)
		return idx;
	Element* enext = elements[idx];
	while (enext->next != NULL && enext->next->key != e->key)
		enext = enext->next;
	if(enext == NULL)
		return -1;
	e = enext->next;
	e->next = e->next->next;
	return e->key;
	delete e;
}
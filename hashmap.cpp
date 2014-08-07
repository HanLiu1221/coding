#include "hashmap.h"

using namespace CODE;

Hashmap::Hashmap()
{
	kcount = 0; 
	ecount = 0;
	elements.resize(capacity);
}

Hashmap::Hashmap(KEY k, VALUE v)
{
	Hashmap();
	Element* e = InitElement(k, v);
	int idx = GetHashIndex(*e);
	elements[idx] = e;
	InMemoryElement ie;
	inMemoryElements.push_back(e);
	ecount++;
}

Element* Hashmap::InitElement(KEY k, VALUE v)
{
	Element* e = new Element;
	e->key = k;
	e->value = v;
	e->next = NULL;
	return e;
}

int Hashmap::GetHashIndex(Element e)
{
	// hash function
	//return (e.key * 11 + (int)e.value.length() % 11) % length;
	return (e.key * 11) % length;
}

int Hashmap::GetHashIndex(KEY k)
{
	// hash function
	return (k * 11) % length;
}

Element* Hashmap::GetElement(KEY k)
{
	int idx = GetHashIndex(k);
	if(elements[idx] == NULL)
		return NULL;
	for(Element* e = elements[idx]; e != NULL; e = e->next)
		if(e->key == k)
			return e;
	return NULL;
}

int Hashmap::AddElement(KEY k, VALUE v)
{
	Element* e = InitElement(k, v);
	int idx = GetHashIndex(*e);
	inMemoryElements.push_back(e);
	if( ecount+1 > capacity)
		ReHash();
		
	if(elements[idx] == NULL) // the element is empty
	{
		elements[idx] = e;
		kcount++;
		ecount++;
		return idx;
	}
	
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
	Element* enext = elements[idx];
	while (enext->next != NULL && enext->next->key != e->key)
		enext = enext->next;
	if(enext == NULL)
		return -1;
	e = enext->next;
	e->next = e->next->next;	
	inMemoryElements.remove(e);
	delete e;
	return idx;	
}

void Hashmap::ReHash(int newCapacity)
{
	vector<Element*> oldElems = elements;
	if(newCapacity > MAX_CAPACITY)
		newCapacity = MAX_CAPACITY;
	elements.resize(newCapacity);
	for(int i = 0; i < olength; ++i)
		elements[i] = oldElems[i];
}

Element* Hashmap::FindRandomElement()
{
	int randidx = rand() % inMemoryElements.Length();
	return inMemoryElements[randidx];
}

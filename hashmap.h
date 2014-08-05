//#ifndef HASHMAP_H
//#define HASHMAP_H

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

namespace CODE
{
	#define KEY int
	#define VALUE string

	int capacity = 1000;

	//class Element
	//{
	//public:
	//	KEY key;
	//	VALUE value;
	//	Element next;
	//	
	//public:
	//	Element(KEY k, VALUE V)
	//	{
	//		key = k;
	//		value = v;
	//		next = NULL;
	//	};
	//};

	struct Element
	{
		KEY key;
		VALUE value;
		struct Element *next;
	};

	class Hashmap
	{
	public:
		vector<Element*> elements; // entries
		int length; // length of hash table
		int ecount; // number of elements
		int kcount; // number of occupied keys
		
	public:
		Hashmap();
		Hashmap(KEY k, VALUE v);
		Element* InitElement(KEY k, VALUE v);
		int GetHashIndex(Element e); // hash function
		int AddElement(KEY k, VALUE v);
		int RemoveElement(KEY k, VALUE v);
		Element NextKeyElement(); // next element in the table
		int ElemCount() { return ecount; }; 
		int KeyCount() { return kcount; }; 
	};
}

//#endif
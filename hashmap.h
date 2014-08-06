#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

namespace CODE
{
	#define KEY int
	#define VALUE string

	int MAT_CAPCITY = 300000;
	int capacity = 1000;
	
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
		vector<InMemoryElement> inmElements;
		int ecount; // number of elements
		int kcount; // number of occupied keys
		
	public:
		Hashmap();
		Hashmap(KEY k, VALUE v);
		Element* InitElement(KEY k, VALUE v);
		int GetHashIndex(Element e); // hash function
		int GetHashIndex(KEY k);
		Element* GetElement(KEY k);
		int AddElement(KEY k, VALUE v);
		int RemoveElement(KEY k, VALUE v);
		Element NextKeyElement(); // next element in the table
		int ElemCount() { return ecount; }; 
		int KeyCount() { return kcount; }; 
		void ReHash(int newCapacity);
		Element* FindRandomElement();
	};
}
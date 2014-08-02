#include <hashmap.h>

namespace CODES
{
	Hashmap::Hashmap()
	{
		hashArray = new HashElement<TYPE1,TYPE2>[HASHSIZE];
		numOfElem = 0;
	}
	Hashmap::Hashmap(HashElement<TYPE1,TYPE2> e)
	{
		Hashmap();
		AddElem(e);
		numOfElem++;
		e.next = null;
	}
	public int Hashmap::AddElem(HashElement<TYPE1,TYPE2> e)
	{
		int loc = 0;
		while(loc < numOfElem && e.first >= hashArray[loc].first)
		{
			loc++;
		}
		if(loc != 0 && hashArray[loc].first == e.first)
			hashArray[loc].second = e.second;
		else
			AddElem(e, loc);
	}

	public void Hashmap::AddElem(HashElement<TYPE1,TYPE2> e, int loc)
	{
		if(loc == 0)
		{
			e.next = null;
			hashArray.next = e;
		}			
		else if(loc < numOfElem)
		{
			e.next = hashArray[loc];
			hashArray[loc] = e;
		}
		else
		{
			if(loc >= HASHSIZE)
			{
				loc = HASHSIZE;
				ReHash();
			}			
			e.next = null;
			hashArray[loc].next = e;
		}
		numOfElem++;
	}

	public void Hashmap::ReHash()
	{
		HashElement<TYPE1,TYPE2>[] OHashArray = new HashElement<TYPE1,TYPE2>[](hashArray);
		hashArray = new HashElement<TYPE1,TYPE2>[HASHSIZE*2];
		for(int i = 0; i < HASHSIZE; ++i)
			hashArray[i] = OHashArray[i];
		HASHSIZE *= 2; 
	}

	public void Hashmap::RemoveElem(int idx)
	{
		HashElement<TYPE1,TYPE2> *head = hashArray;	
		while(head->first != idx)
			head++;
		if(head != null)
		{
			HashElement<TYPE1,TYPE2> *data = head->next;
			head->next = head->next->next;
			delete data;
		}		
	}

	public void Hashmap::RemoveElem(HashElement<TYPE1, TYPE2> e)
	{
		HashElement<TYPE1,TYPE2> *head = hashArray;	
		while(head->first != e.first)
			head++;
		if(head != null)
		{
			HashElement<TYPE1,TYPE2> *data = head->next;
			head->next = head->next->next;
			delete data;
		}		
	}
}
namespace CODES
{
	template<class TYPE1, class TYPE2> 
	class HashElement
	{
		private TYPE1 key;
		private TYPE2 value;
		public HashElement(TYPE1 k, TYPE2 v)
		{
			key = k;
			value = v;
		}
		public TYPE2 GetValue(TYPE1 k)
		{
			return value;
		}
		public void SetValue(TYPE2 v)
		{
			value = v;
		}
	};

	template<class TYPE1, class TYPE2> 
	struct HashElement
	{
		TYPE1 key;
		TYPE2 value;
		struct HashElement *next;
	};

	int HASHSIZE = 1000;

	template<class TYPE1, class TYPE2> 
	class Hashmap
	{
	public:
		int numOfElem; // real number of pairs <key, value>
		HashElement<TYPE1,TYPE2> *hashArray = null;
	public:
		Hashmap();
		Hashmap(HashElement<TYPE1,TYPE2> e);
		~Hashmap();
	public:
		int AddElem(HashElement<TYPE1,TYPE2> e);
		void AddElem(HashElement<TYPE1,TYPE2> e, int loc);
		void RemoveElem(int idx);
		void RemoveElem(HashElement<TYPE1, TYPE2> e);
		void ReHashp();
	};
}
// Implement an algorithm to determine if a string has all unique 
// characters. What if you can not use additional data structure?

bool UniqueTest(string *str)
{
	bool isUnique = true;
	for (int i = 0; i < str->length()-1; ++i)
	{
		for (int j = i+1; j < str->length(); ++j)
		{
			if(str[i] == str[j])
			{
				isUnique = false;
				break;
			}
		}
		if(!isUnique)
			break;
	}
	return isUnique;
}
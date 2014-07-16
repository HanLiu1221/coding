// Design an algorithm and write code to remove the duplicate characters in as string without using any additional buffer.
// NOTE: one or two additional variables are fine. An extra copy of the array is not.
// Write the test cases for this method.

public void RemoveDuplicateChar(string& s)
{
	for(int i = 0; i < s.length() - 1; ++i)
		for(int j =0; j < s.length(); ++j)
		{
			if(s[i] == s[j])
			{
				s.erase(j);
				--j;
			}
		}

}

void main()
{
	string s = "abddujswna";
	RemoveDuplicateChar(s);
}
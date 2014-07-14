// Write code to reverse a C-style string. (C-string means that "abcd" is represented as
// five characters, including the null character.)

void ReverseString(string *str)
{
	int slen = str->length() - 1;
	int hlen = slen/2;
	for(int i = 0; i < hlen; ++i)
	{
		char tmp = str[i];
		str[i] = str[slen-i];
		str[slen-i] = tmp;
	}
}
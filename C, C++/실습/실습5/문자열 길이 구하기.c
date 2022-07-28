#include <stdio.h>

int main()
{
	char str[100];
	int i =0;
	int size=0;
	
	gets(str);
	
	for(i=0; str[i]!= 0; i++)
	{
		if(str[i] == ' ')
		{
			size++;
			continue;
		}
		size++;
	}
	
	printf("%d", size);
	
	return 0;
}
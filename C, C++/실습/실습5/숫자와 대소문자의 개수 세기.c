#include <stdio.h>
#include <ctype.h>

int main()
{
	char text[1000];
	int ch;
	int index = 0;
	
	while((ch = getchar()) != EOF)
	{
		text[index] = ch;
		index++;
	}
	text[index] = '\0';
	
	int i = 0;
	int num_Count = 0;
	int lower_Count = 0;
	int upper_Count = 0;
	
	while(text[i] != 0)
	{
		if(isdigit(text[i]))
		{
			num_Count ++;
			i++;
		}
		else if(isupper(text[i]))
		{
			upper_Count++;
			i++;
		}
		else if(islower(text[i]))
		{
			lower_Count ++;
			i++;
		}
		else
		{
			i++;
		}
	}
	printf("%d %d %d", num_Count, lower_Count, upper_Count);
	return 0;
	
}
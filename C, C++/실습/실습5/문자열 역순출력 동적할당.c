#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *str)
{
  int size = strlen(str);
	
	char* result = (char*)malloc(sizeof(char) * size);
	
	for(int i=0; i<size; i++)
	{
    result[i] = str[size-i-1];
  }
	return result;
}
int main(void)
{
  char str[100];
	char *rev_str;
	
	scanf("%s", str);
	rev_str = reverse(str);
	printf("%s", rev_str);
	free(rev_str);
	
	return 0;
}

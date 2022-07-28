#include <stdio.h>
int main(){
	int a,b,c;
	int tmp;
	
	scanf("%d %d", &a, &b);
 	c=a*b;
	if(a<b){
		tmp = a;
		a=b;
		b=tmp;
	}
	while(b!=0){
		tmp = a%b;
		a=b;
		b=tmp;
	}
	printf("%d\n", c/a);
	return 0;
}
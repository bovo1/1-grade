#include <stdio.h>
#include <stdlib.h>

//소수판별
int is_prime(int k){
	int i;
	for(i = 2; i * i <= k; i++){
		if(k % i == 0)
			return 0;		
	}
		
	return 1;
}

//소수 개수
int count(int n){
	
	int num = 0;
	int j;
	
	for(j = 2; j <= n; j++){
		if(is_prime(j) == 1)
			num++;
		else
			continue;
	}
	
	return num;
	
}


int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", count(n));
	
	return 0;
}


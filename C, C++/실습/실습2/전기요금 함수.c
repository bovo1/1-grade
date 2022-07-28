#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int result(int month, int used_e);

int result(int month, int used_e)
{
	int money_for_e;
	int res;

	if(used_e <= 200)
		money_for_e = floor(910 + (93.3 * used_e));
	else if(used_e > 200 && used_e <= 400)
		money_for_e = floor(1600+200* 93.3+ ((used_e - 200)*187.9));
	else if(used_e >400 && used_e <=1000)
		money_for_e = floor(7300+ 200 *93.3 + 200 * 187.9 + (used_e -400) *280.6);
	else
		if(month == 7 || month == 8 || month == 12 || month == 1 || month ==2)
			money_for_e = floor(7300 + 200 *93.3 + 200 * 187.9 + 600 * 280.6 + (used_e-1000)*709.5);
	  else
			money_for_e = floor(7300+200 *93.3 + 200 * 187.9 + (used_e - 400) * 280.6);
	res = floor(money_for_e) + round(money_for_e*0.1) + floor(money_for_e * 0.037);
  res = res - (res%10);

}

int main(){
	int month;
	int used_e;
	
	scanf("%d", &month);
	scanf("%d", &used_e);
	
	
	printf("%d", result(month, used_e));
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int bill(int month, int used_e) //청구요금을 계산하는 함수
{
	float money_for_e = 0, m = 0, n = 0;
	int res = 0, tax_m = 0, tax_n = 0, elc_money = 0, fin_elc_fee = 0, sum_elc_money = 0;

	if (used_e <= 200)
	{
		money_for_e = (910 + (93.3 * used_e));
		elc_money = money_for_e;
	}
	else if (used_e > 200 && used_e <= 400)
	{
		money_for_e = (1600 + 200 * 93.3 + ((used_e - 200) * 187.9));
		elc_money = money_for_e;

	}
	else if (used_e > 400 && used_e <= 1000)
	{
		money_for_e = (7300 + 200 * 93.3 + 200 * 187.9 + (used_e - 400) * 280.6);
		elc_money = money_for_e;
	}
	else
	{
		if (month == 7 || month == 8 || month == 12 || month == 1 || month == 2)
		{
			money_for_e = (7300 + 200 * 93.3 + 200 * 187.9 + 600 * 280.6 + (used_e - 1000) * 709.5);
			elc_money = money_for_e;
		}
		else
		{
			money_for_e = (7300 + 200 * 93.3 + 200 * 187.9 + (used_e - 400) * 280.6);
			elc_money = money_for_e;
		}

	}


	return elc_money; //전기요금 반환

}


int main() {
	int month, people, i;
	int peo_elc[1000];
	float elc_money_fee = 0;

	scanf("%d", &month);
	scanf("%d", &people);

	for (i = 0; i < people; i++)
	{
		scanf("%d", &peo_elc[i]);
	}

	int minelc = peo_elc[0];
	int maxelc = peo_elc[0];

	for (int i = 0; i < people; i++)
	{
		if (peo_elc[i] < minelc)
		{
			minelc = peo_elc[i];
		}
	}


	for (int i = 0; i < people; i++)
	{
		if (peo_elc[i] > maxelc)
		{
			maxelc = peo_elc[i];
		}
	}


	//여기까지 최소값, 최대값

	int sumelc = 0, sumtax=0; //사용전력량의 합과 세금합
	float avgelc = 0;
	float elcarr[1001], arr1[1001], arr2[1001];
	int taxarr1[1001], taxarr2[1001],taxarr3[1001];
	
	for (int i = 0; i < people; i++)
	{
		sumelc += bill(month, peo_elc[i]);
		elcarr[i] = bill(month, peo_elc[i]);//각각의 전기요금을 넣은 배열
		avgelc += peo_elc[i];
	}
	
	for (int i = 0; i < people; i++)
	{
		arr1[i] = (elcarr[i] * 0.1) + 0.5;
		taxarr1[i] = arr1[i];
		arr2[i] = (elcarr[i] * 0.037);
		taxarr2[i] = arr2[i];

		taxarr3[i] = taxarr1[i] + taxarr2[i];

		sumtax += taxarr3[i];

	}

	avgelc = avgelc / people;
	//printf("%d\n", sumelc);

	int fee = 0;
	int finfee[1001];
	int finsum = 0;
	
	for(int i =0;i<people;i++)
	{
		finfee[i]=(elcarr[i] + taxarr3[i]+5);//청구요금 넣은 배열 (반올림까지 해서)
		finfee[i] = (finfee[i] /10) *10;
		finsum += finfee[i];
	}
	
	
	
	finsum = finsum / people;
	
	printf("%d %d %.1f %d", minelc, maxelc, avgelc, finsum);

	return 0;
}
/*
<해결 방법>

클래스를 선언해준 다음에 생성자를 만들어줬습니다. 생성자에서는 메인함수에서 입력받고 정리한 배열을 넣어주도록 하게 했습니다.
모든 배열들은 메모리를 아끼기 위해서 다 동적할당으로 만들었습니다. 레벨함수에서는 매개변수의 부모값을 temp 라는 변수에 넣어주었습니다.
temp 값을 조건문을 통해서 –1이면 루트값인 0을 반환하고 –1이 아니면 반복문을 사용해서 temp 값이 –1이 될 때까지 하여 반복문이 돌아간 횟수를 레벨값으로 하게 했습니다. 
메인문에서는 사람수와 관계수를 입력받고 관계를 입력받기 위해서 x와 y배열을 동적할당으로 선언해주고 입력받았습니다.
반복문을 이용해서 x배열과 I값이 같은게 있다면 overlap 이라는 함수에 그 인덱스에 1을 넣도록 해주었습니다. 
위에서 배열을 0으로 초기화 해준 상태이므로 1이 아닌 곳은 0이됩니다. 그리고 overlap배열의 값이 0인곳의 인덱스를 skip 이라는 배열에 넣어주었습니다. 
이렇게 되면 overlap 배열은 예시를 예로 들자면 111110101이 됩니다. 6,8번 인덱스에는 0값이 들어가있습니다. 즉 부모값이 없다는 뜻입니다. 
그 다음 반복문이 의미하는 것은 새롭게 할당한 배열에 부모배열을 순서대로 넣어주는 것입니다. 예를 들어 I가 0일 때 x[0]=0입니다. 
그러면 z[0]에다 y[0]값을 넣어주는 방식으로 차례대로 하게 했습니다. x배열에는 부모값이 없는 6과 8은 없기 때문에 z배열의 6번, 8번 인덱스는 0값입니다. 
그래서 skip배열을 이용하여 6번과 8번에 –1값을 넣어주도록 했습니다. 이렇게 보면 overlap 배열과 skip 배열은 빠진 수들을 찾기 위한 배열들입니다.
그 다음에는 생성자를 생성하였고 모든 사람들의 레벨을 저장하기 위해서 lev_arr 배열을 선언하고 레벨을 넣어주고 출력해주었습니다.
*/



#include <iostream>

using namespace std;

class ancestor
{
private:
	int* parent;

public:
	ancestor(int m, int* y);
	int level(int p);
};

ancestor::ancestor(int m, int* y)
{
	parent = new int[m];
	for (int i = 0; i < m; i++)
	{
		parent[i] = y[i];
	}
}

int ancestor::level(int p)
{
	int temp = 0;
	temp = parent[p];
	int d = 0;
	if (temp == -1)
	{
		return 0;
	}
	else
	{
		while (1)
		{
			temp = parent[temp];
			d++;
			if (temp == -1)
			{
				break;
			}
		}
		return d;
	}
}

int main()
{
	int m, n;
	cin >> m;	//사람수
	cin >> n;	//관계수

	int* x = new int[n]();
	int* y = new int[n]();
	int* z = new int[m]();
	int* overlap = new int[m]();
	int* skip = new int[m - n];

	int j = 0;


	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}


	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (x[k] == i)
			{
				overlap[i] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (overlap[i] == 0)
		{
			skip[j] = i;
			j++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		z[x[i]] = y[i];
	}

	for (int i = 0; i < j; i++)
	{
		if (z[skip[i]]==0)
		{
			z[skip[i]] = -1;
		}
	}


	ancestor A(m, z);

	int* lev_arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		lev_arr[i] = A.level(i);
	}

	for (int i = 0; i < m; i++)
	{
		cout << lev_arr[i] << " ";
	}

	delete []lev_arr;
	delete []x;
	delete []y;
	delete []z;
	delete []overlap;
	delete []skip;
	
	return 0;
}

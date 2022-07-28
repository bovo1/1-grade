#include <iostream>
#include <cmath>

using namespace std;

class ancestor
{
private:
	int* parent;	//부모배열

public:
	ancestor(int m, int* y);
	int level(int p);
	int distance(int p1, int p2);
	int LowestAncestor(int p1, int p2);
};

ancestor::ancestor(int m, int* y)
{
	parent = new int[m];
	for (int i = 0; i < m; i++)
	{
		parent[i] = y[i];
	}
}

//만약에 입력된 수가 아닌 수를 입력하면 -1 이 나와야할듯?
int ancestor::level(int p)
{
	int temp = 0;
	temp = parent[p]; 
	int d = 0;

	if (temp == -1)
	{
		return 0;
	}
	else if(temp != -1)
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
	else
	{
		return -1;
	}
}
int ancestor::distance(int p1, int p2)
{
	//공통조상을 찾아서 공통조상의 레벨에서 p1의 레벨을 뺀거 + p2의 레벨을 뺀거
	int p1dis = 0;
	int p2dis = 0;
	int comance = LowestAncestor(p1, p2);
	if (comance == -1)
	{
		return -1;
	}
	else if(comance != -1)
	{
		int comance_lev = level(comance);
		int p1lev = level(p1);
		int p2lev = level(p2);
		p1dis = comance_lev - p1lev;
		p2dis = comance_lev - p2lev;

		return abs(p1dis + p2dis);
	}
	else
	{
		return -1;
	}
}
int ancestor::LowestAncestor(int p1, int p2)
{
	//parent배열에서 p1과 p2의 부모를 찾는데 서로 같은 부모가 있다면 break 하고 반환
	//만약 3레벨에 있는 값과 2레벨에 있는 값의 공통조상을 찾는다고 하면 2레벨에 맞춰서 한다.
	
	int p1temp = p1, p2temp =p2;
	int dis = 0,i=0;

	if (level(p1) > level(p2))
	{
		dis = abs(level(p1) - level(p2));
		for (i = 0; i < dis; i++)
		{
			p1temp = parent[p1temp];
		}
		if (p1temp == p2temp)
		{
			return p1temp;
		}
		else
		{
			goto repeat;
		}
	}
	else if (level(p1) < level(p2))
	{
		dis = abs(level(p1) - level(p2));
		for (i = 0; i < dis; i++)
		{
			p2temp = parent[p2temp];
		}
		if (p1temp == p2temp)
		{
			return p1temp;
		}
		else
		{
			goto repeat;
		}
	}
	else if (level(p1) == level(p2))
	{
		if (p1 == p2)
		{
			return p1;
		}
		else if (parent[p1] == -1 && parent[p2] == -1)
		{
			return -1;
		}
		else
		{
		repeat:
			if (p1temp == 0 || p2temp == 0)
			{
				return -1;
			}
			else
			{
				for (i = 0; i < level(p1); i++)
				{
					p1temp = parent[p1temp];
					p2temp = parent[p2temp];

					if (p1temp != p2temp)
					{
						continue;
					}
					else if (p1temp == p2temp)
					{
						return p1temp;
					}
					else if (parent[p1temp] == -1 && parent[p2temp] == -1)
					{
						return -1;
					}
				}
			}
		
		}
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

	int s;
	cin >> s;
	int* karr1 = new int[s];
	int* karr2 = new int[s];

	for (int i = 0; i < s; i++)
	{
		cin >> karr1[i] >> karr2[i];
	}

	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (x[k] == i)
			{
				overlap[i] = 1;		//같은 것이 있다면 1 아니면 0(위에서 배열을 0으로 초기화해준상태)
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (overlap[i] == 0)
		{
			skip[j] = i;	//0일때 skip 배열에 그 인덱스를 넣어주기.
			j++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		z[x[i]] = y[i];		//값을 0123~ 순서대로 맞춰주기 위함.
	}

	for (int i = 0; i < j; i++)
	{
		if (z[skip[i]] == 0)
		{
			z[skip[i]] = -1;	//0인곳에 -1을 넣어줌. 루트를 뜻함.
		}
	}

	ancestor A(m, z);

	int* lev_arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		lev_arr[i] = A.level(i);	//각 레벨을 넣어줌.
	}

	for (int i = 0; i < s; i++)		//최소 공통조상과 거리를 출력.
	{
		cout << A.LowestAncestor(karr1[i], karr2[i]) << " " << A.distance(karr1[i], karr2[i]) << endl;
	}
	
	delete []lev_arr;
	delete []karr1;
	delete []karr2;
	delete []x;
	delete []y;
	delete []z;
	delete []overlap;
	delete []skip;
	
	return 0;
}
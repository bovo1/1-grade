#include <iostream>
#include <cmath>

using namespace std;

class ancestor
{
private:
	int* parent;

public:
	ancestor(int m, int* y);
	int level(int p);
	//int distance(int p1, int p2);
	//int LowestAncestor(int p1, int p2);
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
	temp = parent[p]; //1부터 시작하는 트리라면 안됨. 수정필요
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

	return 0;
}
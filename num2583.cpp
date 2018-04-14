#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int rec[101][101];
queue<int> xque;
queue<int> yque;
vector<int> subsum;
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, -1, 0, 1 };

int m, n, k;

int area = 0;

void bfs(int x, int y)
{
	int sum = 0;
	rec[x][y] = 1;
	xque.push(x);
	yque.push(y);

	while (xque.size()>0)
	{
		int x = xque.front();
		int y = yque.front();
		xque.pop(); yque.pop();

		sum++;

		for (int i = 0; i<4; i++)
		{
			int nextX = x + a[i];
			int nextY = y + b[i];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && rec[nextX][nextY] == -1)
			{
				rec[nextX][nextY] = 1;
				xque.push(nextX);
				yque.push(nextY);
			}
		}
	}
	subsum.push_back(sum);
	area++;

}

int main()
{
	int x1, y1, x2, y2;
	memset(rec, -1, sizeof(rec));
	cin >> m >> n >> k;

	for (int i = 0; i<k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int p = y2 - 1; p >= y1; p--)
		{
			for (int q = x2 - 1; q >= x1; q--)
			{
				rec[p][q] = 0;
			}
		}

	} //정사각형 범위 0으로 만들기

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (rec[i][j] == -1)
				bfs(i, j);
		}
	}

	cout << area << endl;
	sort(subsum.begin(), subsum.end());
	for (int i = 0; i<subsum.size(); i++)
	{
		printf("%d ", subsum[i]);
	}


	return 0;
}

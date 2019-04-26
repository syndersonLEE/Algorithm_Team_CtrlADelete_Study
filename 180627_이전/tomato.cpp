/*Question 7576 ≈‰∏∂≈‰ in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<algorithm>
#include<queue>
#define MAX_NUM 1001
using namespace std;
int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0 ,0 };
int box[MAX_NUM][MAX_NUM];

class xy {
public:
	int x, y;
	xy(int a, int b) :x(a), y(b) {}
};

int main(){
	queue<xy> q;
	int wid, hei;
	int ripe = 0; 
	int unripe = 0;
	scanf("%d %d", &wid, &hei);
	for (int i = 0;i < hei;i++) {
		for (int j = 0;j < wid;j++) {
			scanf("%d", &box[i][j]);
			
			if (box[i][j] == 1) {
				ripe++;
				q.push(xy(i, j));
			}

			if (box[i][j] == 0) 
				unripe++;
		}
	}

	if (!unripe) {
		printf("0\n");
		return 0;
	}

	q.push(xy(-1, -1));
	int day = 0;
	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		q.pop();

		if (cur_x == -1) {
			if (!q.empty()) {
				day++;
				q.push(xy(-1, -1));
				continue;
			}

			else {
				if (unripe) {
					printf("%d\n", day);
					return 0;
				}

				else {
					printf("0\n");
					return 0;
				}
			}
		}

		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 4;j++) {
				int nx = cur_x + x[i];
				int ny = cur_y + y[j];
				if (0 <= nx && nx <= hei && 0 <= ny && ny <= wid && box[nx][ny] == 0) {
					q.push(xy(nx, ny));
					ripe++;
					unripe--;
				}
			}
		}
	}
	return 0;

}
/*
#include<cstdio>
#include<queue>

using namespace std;

const int move_x[4] = { 0, 0, 1, -1 };
const int move_y[4] = { 1, -1, 0, 0 };

int box[1000][1000] = {};
class xy
{
public:
	int x, y;
	xy(int a, int b) :x(a), y(b) {}
};
int main()
{
	int n, m, count = 0, ripe = 0, unripe = 0;
	queue<xy>Queue;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				Queue.push(xy(i, j)), ripe++;

			else if (box[i][j] == 0)
				unripe++;
		}

	if (!unripe)
	{
		printf("0\n");
		return 0;
	}

	Queue.push(xy(-1, -1));
	while (!Queue.empty())
	{
		xy pos = Queue.front();
		Queue.pop();

		if (pos.x == -1)
		{
			if (!Queue.empty())
			{
				count++;
				Queue.push(xy(-1, -1));
				continue;
			}

			else
				break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = pos.x + move_x[i], ny = pos.y + move_y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !box[nx][ny])
				unripe--, box[nx][ny] = 1, Queue.push(xy(nx, ny));

		}


	}

	if (unripe)
		printf("-1\n");

	else
		printf("%d\n", count);


}
*/
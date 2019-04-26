//RGB∞≈∏Æ BaekJoon Solved by ¿ÃªÛ¿±

#include<cstdio>
#include<algorithm>

using namespace std;

int box[1001][3];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		if (i == 0) { box[0][0] = r; box[0][1] = g; box[0][2] = b; }
		else {
			box[i][0] = min(box[i - 1][1] + r, box[i - 1][2] + r);
			box[i][1] = min(box[i - 1][0] + g, box[i - 1][2] + g);
			box[i][2] = min(box[i - 1][0] + b, box[i - 1][1] + b);
		}
	}
	int ans = min(box[n - 1][0], box[n - 1][1]);
	ans = min(ans, box[n - 1][2]);
	printf("%d\n", ans);

}
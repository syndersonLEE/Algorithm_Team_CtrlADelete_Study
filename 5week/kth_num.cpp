/*Question 11004 K¹øÂ° ¼ö in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	long long *box = new long long[n];
	for (int i = 0;i < n;i++)
		scanf("%lld", &box[i]);
	sort(box, box + n);
	printf("%lld\n",box[m-1]);
	delete[] box;
	return 0;
}
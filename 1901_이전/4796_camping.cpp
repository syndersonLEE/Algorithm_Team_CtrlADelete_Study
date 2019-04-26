#include<stdio.h>

using namespace std;

int l, p, v;
int totDays, ans, rest, temp;

int main() {
	scanf("%d %d %d", &l, &p, &v);
	for (int i = 0; !(l == 0 && p == 0 && v == 0);i++) {
		ans = 0;
		totDays = v;
		temp = (v / p);
		ans += temp * l;

		rest = v - (temp * p);
		if (rest < l) {
			ans += rest;
		}
		else {
			ans += l;
		}
		printf("Case %d: %d\n", i, ans);
		scanf("%d %d %d", &l, &p, &v);
	}
}
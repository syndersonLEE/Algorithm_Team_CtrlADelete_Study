// 동전 1 Solved by 이상윤 BaekJoon Algorithm

#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int coin[101];
int price[10001];

int coin_func(int kind) {
	if (kind == 1) {
		price[kind] = 1;
		return 1;
	}
	
	else if (price[kind] != 0) {
		return price[kind];
	}

	else {
		int temp = 0;
		for (int i = n; i >= 1; i--) {
			if (kind - coin[i] > 0) {
				temp += coin_func(kind - coin[i]);
			}
			if (coin[i] == kind)
				temp += 1;
		}
		price[kind] = temp;
		return price[kind];
	}
}

int main() {
	int kind;
	scanf("%d %d", &n, &kind);
		for (int i = 1; i <= n; i++) 
		scanf("%d", &coin[i]);
	coin_func(kind);
	printf("%d\n", price[kind]);
	
}
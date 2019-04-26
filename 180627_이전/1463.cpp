//1로 만들기 BaekJoon Solved by 이상윤

#include<cstdio>
#include<algorithm>

using namespace std;

int arr[1000001];

int makeone(int num){
	if (num == 1) return 0;
	if (arr[num] != 0) return arr[num];
	else {
		int result = makeone(num-1) + 1;
		if (num % 3 == 0) result = min(makeone(num / 3) + 1, result);
		if (num % 2 == 0) result = min(makeone(num / 2) + 1, result);
		arr[num] = result;
		return result;
	}
}

int main() {
	int i;
	scanf("%d", &i);
	printf("%d\n",makeone(i));
	return 0;
}
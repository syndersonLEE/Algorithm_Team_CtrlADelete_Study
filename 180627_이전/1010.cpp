// 다리 놓기 solved by 이상윤

#include<cstdio>

using namespace std;

int path[31][31];

int bridge(int west, int east) {
	if (path[west][east] != 0)
		return path[west][east];

	else if (west == east) {
		path[west][east] = 1;
		return 1;
	}

	else if (west == 1) {
		path[west][east] = east;
		return east;
	}

	else {
		int temp = 0;
		int temp_east = east - 1;
		while (west - 1 <= temp_east||temp_east != 0) {
			temp += bridge(west-1,temp_east);
			temp_east--;
		}
		path[west][east] = temp;
		return path[west][east];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int west, east;
		scanf("%d %d", &west, &east);
		bridge(west, east);
		printf("%d\n", path[west][east]);
	}
}
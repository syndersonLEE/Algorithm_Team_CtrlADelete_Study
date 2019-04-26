#include<cstdio>
#include<vector>

using namespace std;

int m, n;
string temp;
vector<string> s;

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%s", temp);
		s.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		if ('0' <= temp[0] && temp[0] <= '9') {
			int num = 0;
			for (int j = 0; temp[j] != '\0'; j++) {
				num *= 10;
				num += temp[j];
			}

			printf("%s\n", s[num]);
		}

		else {
			int left, right, mid;
			left = 0; right = m;
			while (left <= right) {
				mid = (left + right) / 2;
				if (temp == s[mid]) {
					printf("%s", s[mid]);
				}
				else {}
			}
		}

	}
}
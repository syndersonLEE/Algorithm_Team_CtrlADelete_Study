//Solved By SANGYUNLEE

#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int testCases;
int push_num;
char c[7];
vector<int> v;

int main() {
	scanf("%d", &testCases);
	v.clear();
	while (testCases--) {
		scanf("%s", c);
		if (strcmp("push",c) == 0) {
			scanf("%d", &push_num);
			v.push_back(push_num);
		}
		else if (strcmp("pop", c) == 0 || strcmp("top", c) == 0) {
			int temp;
			if (!v.empty()) {
				temp = v.back();
				if (strcmp("pop", c) == 0) {
					v.pop_back();
				}
				printf("%d\n", temp);
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp("size",c) == 0) {
			printf("%d\n", v.size());
		}

		else if (strcmp("empty", c) == 0) {
			printf("%d\n", v.empty());
		}
	}
}
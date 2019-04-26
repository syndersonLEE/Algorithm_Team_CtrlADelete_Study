#include <cstdio>

int Load() {
	int x;
	FILE *fp = fopen("input.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d", &x);
	}
	fclose(fp);
	return x;
}

void Store(int data) {
	FILE *fp = fopen("input.txt", "a");
	fprintf(fp, "%d\n", data);
	fclose(fp);
}

int Add(int i, int j) {
	return i + j;
}

// 데이타 화일의 open, close는 Load, Store 각 함수 안에서 매번 수행하게할 것
void main() {
	int x;
	for(int i=0;i<10000;i++){
			x = Load();
			x = Add(x, 1);
			Store(x);
	}
	printf("%d\n", x);
}
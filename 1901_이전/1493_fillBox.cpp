#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int L, W, H;
int cubeNum, temp1, temp2;
bool failCheck = false;
pair<int, int> q[21];

int cubeCheck(int len,int wid,int hei) {
	int numCube = 1;
	if (len == 0 || wid == 0 || hei == 0) {
		return 0;
	}

	int maxCube = -1;
	for (int i = 0; i < cubeNum; i++) {
		if(q[i].second != 0 && len >= -q[i].first && wid >= -q[i].first && hei >= -q[i].first){
			maxCube = -q[i].first;
			q[i].second--;
			break;
		}
	}

	if (maxCube == -1 || failCheck) {
		failCheck = true;
		return -1;
	}
	else {
		 numCube += (cubeCheck(maxCube, maxCube, hei - maxCube)
		+ cubeCheck(len - maxCube, maxCube, maxCube)
		+ cubeCheck(maxCube, wid - maxCube, maxCube)
		+ cubeCheck(maxCube, wid - maxCube, hei - maxCube)
		+ cubeCheck(len - maxCube, wid - maxCube, maxCube)
		+ cubeCheck(len - maxCube, maxCube, hei - maxCube)
		+ cubeCheck(len - maxCube, wid - maxCube, hei - maxCube));
		 if (!failCheck) {
			 return numCube;
		 }
		 else {
			 return -1;
		 }
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin >> L >> W >> H >> cubeNum;
	for (int i = 0; i < cubeNum; i++) {
		cin >> temp1 >> temp2;
		q[i] = { -pow(2,temp1), temp2 };
	}
	sort(q, q + cubeNum);

	cout << cubeCheck(L, W, H) << "\n";

}
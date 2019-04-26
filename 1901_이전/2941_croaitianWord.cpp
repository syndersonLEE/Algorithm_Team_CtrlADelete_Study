#include<iostream>
#include<string>

using namespace std;

string s;
int ans = 0;

int main() {
	ios::sync_with_stdio;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i < (s.size() - 1)) {
			if (s[i] == 'c') {
				if (s[i + 1] == '=') {
					ans++;
					i++;
				}
				else if (s[i + 1] == '-') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
			}
			else if (s[i] == 'd') {
				if (s[i + 1] == 'z' && i < (s.size() - 2)) {
					if (s[i + 2] == '=') {
						ans++;
						i++;
						i++;
					}
					else {
						ans++;
					}
				}
				else if (s[i + 1] == '-') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
				
			}
			else if (s[i] == 'l') {
				if (s[i + 1] == 'j') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
			}
			else if (s[i] == 'n') {
				if (s[i + 1] == 'j') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
			}
			else if (s[i] == 's') {
				if (s[i + 1] == '=') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
			}
			else if (s[i] == 'z') {
				if (s[i + 1] == '=') {
					ans++;
					i++;
				}
				else {
					ans++;
				}
			}
			else {
				ans++;
			}
		}
		else {
			ans++;
		}
	}
	cout << ans << "\n";
}
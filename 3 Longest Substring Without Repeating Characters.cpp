#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void main() {
	string s;
	while (cin >> s) {
		string str = "";
		string maxstr = "";
		for (int j = 0;j < (int)s.size();j++) {
			for (int i = j;i < (int)s.size();i++) {
				if (str.find(s[i]) == string::npos) {
					str += s[i];
					if (str.size() > maxstr.size())
						maxstr = str;
				}
				else {
					str = "";
					str += s[i];
				}
			}
		}
		cout << maxstr.size() << endl;
	}

}
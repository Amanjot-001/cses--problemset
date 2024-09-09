// best template for substr => (window + hashmap) problems
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin >> s;

	vector<int> map(128, 0);
	int counter=0, begin=0, end=0, d=0;
	
	while(end<s.size()) {
		if(map[s[end++]]++ == 0)
			counter++;
		while(counter>1) {
			if(map[s[begin++]]-- == 1)
				counter--;
		}
		d = max(d, end-begin);
	}

	cout << d << '\n';

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	string s = "hello";
	char k = 'l';

	int consec_len=0;
	int max_consec=0;
	vector<int> arr;

	for(int i=0; i<s.size(); i++) {
		char ch = s[i];
		if(ch == k) {
			consec_len++;
		} 
		else if(consec_len != 0) {
			arr.push_back(consec_len);
			max_consec = max(consec_len, max_consec);
			consec_len=0;
		}
	}

	if (consec_len != 0) {
        arr.push_back(consec_len);
        max_consec = max(consec_len, max_consec);
    }

	int ans=0;
	bool max_used=false;
	for(auto& it : arr) {
		if(!max_used && it == max_consec) {
			max_used=true;
		} else {
			ans += it;
		}
	}

	cout << ans << '\n';

	return 0;
}
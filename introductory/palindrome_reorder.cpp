#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    
    for(const char& ch: s)
        freq[ch]++;
    
    int i = 0, j = s.size() - 1;
    char oddChar = '\0';
    bool hasOdd = false;
    
    for(auto& it : freq) {
        int x = it.second;
        
        if(x % 2 != 0) {
            if(hasOdd) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            }
            hasOdd = true;
            oddChar = it.first;
        }
        
        for(int k = 0; k < x / 2; k++) {
            s[i++] = it.first;
            s[j--] = it.first;
        }
    }
    
    if(hasOdd) {
        s[i] = oddChar;
    }

    cout << s << '\n';
    return 0;
}


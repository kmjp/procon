#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int C[256][256];

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int i,j;
        ZERO(C);
		FORR(a,mappings) C[a[0]][a[1]]=1;
        for(i=0;i+sub.size()<=s.size();i++) {
			FOR(j,sub.size()) {
				if(sub[j]==s[i+j]) continue;
				if(C[sub[j]][s[i+j]]) continue;
				break;
			}
			if(j==sub.size()) return 1;
			
		}
        return 0;
    }
};

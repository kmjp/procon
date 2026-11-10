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


class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
		int same=1;
		vector<vector<string>> R;
		int i;
		FOR(i,s1.size()) {
			if(s1[i]==s2[i]) {
				same=1;
			}
			else {
				if(same) {
					R.push_back({"",""});
				}
				R.back()[0]+=s1[i];
				R.back()[1]+=s2[i];
				same=0;
			}
		}
		return R;
        
    }
};

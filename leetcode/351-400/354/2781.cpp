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

set<string> NG[11];


class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int i;
        FOR(i,11) NG[i].clear();
        FORR(f,forbidden) NG[f.size()].insert(f);
        int ma=0;
        string S;
        FORR(c,word) {
			S+=c;
			for(i=1;i<=10;i++) if(S.size()>=i) {
				if(NG[i].count(S.substr(S.size()-i))) {
					S=S.substr(S.size()-i+1);
				}
			}
			
			ma=max(ma,(int)S.size());
		}
		return ma;
    }
};

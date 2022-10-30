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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
		vector<string> R;
        FORR(q,queries) {
			int ok=0;
			FORR(s,dictionary) if(s.size()==q.size()) {
				int i;
				int dif=0;
				FOR(i,s.size()) dif+=s[i]!=q[i];
				if(dif<=2) ok=1;
			}
			if(ok) R.push_back(q);
		}
		return R;
    }
};



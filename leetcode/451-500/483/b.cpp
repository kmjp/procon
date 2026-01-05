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
    vector<vector<string>> wordSquares(vector<string>& words) {
		vector<vector<string>> V;
		FORR(a,words) FORR(b,words) FORR(c,words) FORR(d,words) {
			if(a==b) continue;
			if(a==c) continue;
			if(a==d) continue;
			if(b==c) continue;
			if(b==d) continue;
			if(c==d) continue;
			if(a[0]!=b[0]) continue;
			if(c[3]!=d[3]) continue;
			if(a[3]!=c[0]) continue;
			if(b[3]!=d[0]) continue;
			V.push_back({a,b,c,d});
			
		}
		sort(ALL(V));
		return V;
        
    }
};

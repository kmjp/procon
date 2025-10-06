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
    string removeSubstring(string s, int k) {
		vector<pair<char,int>> V;
		FORR(a,s) {
			if(V.empty()||V.back().first!=a) V.push_back({a,0});
			V.back().second++;
			if(V.size()>=2&&V[V.size()-1].second==k&&V.back().first==')'&&V[V.size()-2].second>=k) {
				V.pop_back();
				V.back().second-=k;
				if(V.back().second==0) V.pop_back();
			}
		}
		string r;
		int i;
		FORR2(a,b,V) FOR(i,b) r+=a;
        return r;
    }
};



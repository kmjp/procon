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

const ll mo=1000000007;
ll from[2020];
ll to[2020];
class Solution {
public:
    int possibleStringCount(string word, int k) {
		vector<pair<int,int>> V;
		FORR(c,word) {
			if(V.empty()||V.back().first!=c) V.push_back({c,0});
			V.back().second++;
		}
		if(V.size()>=k) {
			ll ret=1;
			FORR(v,V) ret=ret*v.second%mo;
			return ret;
		}
		
		ZERO(from);
		from[0]=1;
		int x;
		FORR(v,V) {
			int y=v.second;
			ZERO(to);
			for(x=0;x<=k;x++) {
				to[x+1]+=from[x];
				if(x+y<=k) {
					to[x+y+1]+=mo-from[x];
				}
				else {
					int more=x+y-k;
					to[k+1]+=mo-from[x];
					(to[k]+=more*from[x])%=mo;
					
				}
			}
			for(x=0;x<=k;x++) {
				from[x]=to[x]%mo;
				if(x) (from[x]+=from[x-1])%=mo;
			}
		}
		
		return from[k]%mo;
			
		
        
    }
};

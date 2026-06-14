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
    long long maxRatings(vector<vector<int>>& units) {
        int H=units.size();
        int W=units[0].size();
        ll ret=0;
		FORR(v,units) sort(ALL(v));
        if(W==1) {
			FORR(v,units) ret+=v[0];
		}
		else if(H==1) {
			ret=units[0][0];
		}
		else {
			vector<ll> C;
			ll mi=1<<30;
			FORR(v,units) {
				mi=min(mi,(ll)v[0]);
				C.push_back(v[1]);
			}
			sort(ALL(C));
			C[0]=mi;
			FORR(a,C) ret+=a;
		}
		return ret;
		
    }
};

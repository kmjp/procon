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

vector<ll> C[2];

class Solution {
public:
    long long minOperations(vector<int>& nums) {
		if(C[0].empty()) {
			for(ll a=1;a<=100000;a++) {
				string A=to_string(a);
				string B=A;
				reverse(ALL(B));
				ll v=atoll((A+B).c_str());
				A.pop_back();
				ll w=atoll((A+B).c_str());
				if(v<=3000000000) C[v%2].push_back(v);
				if(w<=3000000000) C[w%2].push_back(w);
			}
		}
        sort(ALL(C[0]));
        sort(ALL(C[1]));
        ll ret=0;
        FORR(a,nums) {
			int x=lower_bound(ALL(C[a%2]),a)-C[a%2].begin();
			if(C[a%2][x]!=a) {
				ret+=min(C[a%2][x]-a,a-C[a%2][x-1]);
			}
		}
		return ret/2;
        
    }
};

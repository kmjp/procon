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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
		vector<ll> V;
		int i;
		FOR(i,30) if(n&(1<<i)) V.push_back(1<<i);
		
		const ll mo=1000000007;
		vector<int> R;
		FORR(v,queries) {
			ll a=1;
			for(int i=v[0];i<=v[1];i++) a=a*V[i]%mo;
			R.push_back(a);
		}
        return R;
    }
};

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
    vector<int> findCoins(vector<int>& numWays) {
        int N=numWays.size();
        vector<ll> C(N);
        int i,j;
        vector<int> ret;
        FOR(i,N) if(C[i]!=numWays[i]) {
			if(C[i]+1!=numWays[i]) return {};
			int add=i+1;
			ret.push_back(add);
			C[i]++;
			for(j=add+1;j<=N;j++) C[j-1]+=C[j-1-add];
		}
		return ret;
    }
};



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
    vector<vector<int>> findPrimePairs(int n) {
		vector<int> P(n+1);
		vector<vector<int>> R;
		int i,j;
		for(i=2;i<=n/2;i++) if(P[i]==0) {
			for(j=i*2;j<=n;j+=i) P[j]=1;
		}
		for(i=2;i<=n/2;i++) if(P[i]==0) {
			if(P[n-i]==0) R.push_back({i,n-i});
		}
        return R;
    }
};

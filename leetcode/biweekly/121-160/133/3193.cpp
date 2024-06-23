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
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
		vector<int> R[303];
		
		FORR(v,requirements) {
			R[v[0]].push_back(v[1]);
		}
		int i,j,a;
		ll from[404]={};
		from[0]=1;
		FOR(i,n) {
			ll to[404]={};
			for(j=0;j<=400;j++) {
				for(a=0;a<=i&&a+j<=400;a++) to[a+j]+=from[j];
			}
			
			
			for(j=0;j<=400;j++) from[j]=to[j]%mo;
			sort(ALL(R[i]));
			if(R[i].size()&&R[i][0]!=R[i].back()) return 0;
			if(R[i].size()) {
				FOR(j,404) if(j!=R[i][0]) from[j]=0;
			}
		}
		ll ret=0;
		FOR(i,404) ret+=from[i];
		return ret%mo;
        
    }
};

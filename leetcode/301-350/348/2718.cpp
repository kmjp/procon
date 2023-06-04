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

int RH[10101],CH[10101];
int RV[10101],CV[10101];

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
		MINUS(RH);
		MINUS(CH);
		ZERO(RV);
		ZERO(CV);
		int i;
		FOR(i,queries.size()) {
			if(queries[i][0]==0) {
				RH[queries[i][1]]=i;
				RV[queries[i][1]]=queries[i][2];
			}
			else {
				CH[queries[i][1]]=i;
				CV[queries[i][1]]=queries[i][2];
			}
		}
		vector<pair<int,int>> ev;
		FOR(i,n) {
			if(RH[i]>=0) ev.push_back({-RH[i],i});
			if(CH[i]>=0) ev.push_back({-CH[i],i+100000});
		}
		ll ret=0;
		int NC=n,NR=n;
		sort(ALL(ev));
		FORR(a,ev) {
			if(a.second<100000) {
				int r=a.second;
				ret+=1LL*RV[r]*NC;
				NR--;
			}
			else {
				int c=a.second-100000;
				ret+=1LL*CV[c]*NR;
				NC--;
			}
		}
		return ret;
		
        
    }
};
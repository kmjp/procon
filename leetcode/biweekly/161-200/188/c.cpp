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

ll B[50505];

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
		ZERO(B);
		FORR(b,boosts) {
			B[b[0]]+=b[2];
			B[b[1]+1]-=b[2];
		}
		int N=monsters.size();
		int i,j;
		FOR(i,N) B[i+1]+=B[i];
		ll ret=(1LL<<60)-1;
		for(i=59;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			
			FOR(j,N) {
				if(tmp+B[j]<monsters[j]) break;
				tmp=max(0LL,tmp-monsters[j]);
			}
			if(j==N) ret-=1LL<<i;
			
			
		}
		return ret;
			
		
        
    }
};

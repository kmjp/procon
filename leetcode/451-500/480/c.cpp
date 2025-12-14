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
    long long minMoves(vector<int>& balance) {
		int i;
		int N=balance.size();
		FOR(i,N) if(balance[i]<0) break;
		if(i==N) return 0;
		int center=i;
		ll ret=0;
		for(i=1;i<N;i++) {
			int j=(center-i+N)%N;
			int k=(center+i)%N;
			{
				ll mi=min(balance[j],-balance[center]);
				ret+=mi*i;
				balance[center]+=mi;
				balance[j]-=mi;
			}
			{
				ll mi=min(balance[k],-balance[center]);
				ret+=mi*i;
				balance[center]+=mi;
				balance[k]-=mi;
			}
		}
		if(balance[center]<0) ret=-1;
		return ret;
        
    }
};



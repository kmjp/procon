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

ll C[201010];
ll D[201010];
int R,K,N;
class Solution {
public:
	int can(ll v) {
		int i;
		ll L=K;
        FOR(i,N) {
			D[i]=C[i];
			if(i) D[i]-=C[i-1];
		}
        FOR(i,N) {
			if(i) D[i]+=D[i-1];
			if(D[i]<v) {
				L-=v-D[i];
				if(L<0) return 0;
				D[i+R]-=v-D[i];
				D[i]+=v-D[i];
			}
		}
		return L>=0;
	}
    long long maxPower(vector<int>& stations, int r, int k) {
        N=stations.size();
        int i;
        FOR(i,N) C[i]=0;
        FOR(i,N) {
			C[max(i-r,0)]+=stations[i];
			C[i+r+1]-=stations[i];
		}
		for(i=1;i<N;i++) C[i]+=C[i-1];
		R=2*r+1;
		K=k;
		int ma=0;
		ll ret=0;
		for(i=60;i>=0;i--) if(can(ret+(1LL<<i))) ret+=1LL<<i;
		return ret;
		
		
    }
};

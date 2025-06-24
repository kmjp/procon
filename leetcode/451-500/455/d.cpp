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


int ma[1<<12];

double dp[1<<12][5];

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        int mask;
        int i;
        FOR(mask,1<<n) {
			ma[mask]=0;
			FOR(i,n) if(mask&(1<<i)) ma[mask]=max(ma[mask],time[i]);
			FOR(i,5) dp[mask][i]=1e9;
		}
		dp[(1<<n)-1][0]=0;
		priority_queue<pair<double,int>> Q;
		Q.push({0,((1<<n)-1)*10+0});
		while(Q.size()) {
			double co=-Q.top().first;
			int mask=Q.top().second/10;
			int step=Q.top().second%10;
			Q.pop();
			if(dp[mask][step]!=co) continue;
			if(mask==0) return co;
			
			if(__builtin_popcount(mask)<=k) {
				double co2=co+ma[mask]*mul[step];
				if(chmin(dp[0][0],co2)) Q.push({-co2,0});
			}
			
			int sm;
			for(sm=(mask-1)&mask;sm>0;sm=(sm-1)&mask) if(__builtin_popcount(sm)<=k) {
				double co2=co+ma[sm]*mul[step];
				int nstep=(step+int(ma[sm]*mul[step]))%m;
				FOR(i,n) if((((1<<n)-1)^mask^sm)&(1<<i)) {
					double co3=co2+time[i]*mul[nstep];
					int mstep=(nstep+int(floor(time[i]*mul[nstep])))%m;
					if(chmin(dp[mask^sm^(1<<i)][mstep],co3)) Q.push({-co3,(mask^sm^(1<<i))*10+mstep});
				}
			}
			
		}
		return -1;
    }
};



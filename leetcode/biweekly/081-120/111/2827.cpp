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

ll V,K;
ll p10[11];
ll dp[11][22][21][2][2];

class Solution {
public:
	ll hoge(int d,int dif,int mo,int lz,int le) {
		if(d<0) {
			return (dif==10)&&(mo==0);
		}
		if(dp[d][dif][mo][lz][le]>=0) return dp[d][dif][mo][lz][le];
		ll ret=0;
		int v=V/p10[d]%10;
		int i;
		
		FOR(i,10) {
			if(le==0&&i>v) continue;
			int nd=dif;
			if(i!=0||lz) {
				if(i%2) nd++;
				else nd--;
			}
			ret+=hoge(d-1,nd,(mo+p10[d]*i)%K,lz|(i>0),le|(i<v));
			
		}
		
		return dp[d][dif][mo][lz][le]=ret;
	}

    int numberOfBeautifulIntegers(int low, int high, int k) {
		p10[0]=1;
		int i;
		FOR(i,10) p10[i+1]=p10[i]*10;
		K=k;
		V=high;
		MINUS(dp);
		ll ret=hoge(10,10,0,0,0);
		V=low-1;
		MINUS(dp);
		ret-=hoge(10,10,0,0,0);
		return ret;
        
    }
};

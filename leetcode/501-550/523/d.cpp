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

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int dp[1010];
int dp2[1010][1010];


class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
		cprime();
		
		vector<int> P;
		FORR(p,prime) if(p<=n) P.push_back(p);
		
		int i,j;
		FOR(i,s+1) dp[i]=1<<30;
		dp[0]=0;
		ZERO(dp2);
		
		for(i=P.size()-1;i>=0;i--) {
			int p=P[i];
			for(int cur=s;cur>=p;cur--) if(dp[cur-p]<1000) {
				int num=dp[cur-p]+1;
				if(num<=dp[cur]) {
					dp[cur]=num;
					dp2[i][cur]=1;
				}
			}
		}
		int cur=s;
		while(dp[cur]>1000) cur--;
		
		vector<int> ret;
		FOR(i,P.size()) if(dp2[i][cur]) {
			ret.push_back(P[i]);
			cur-=P[i];
		}
		return ret;
			
        
    }
};



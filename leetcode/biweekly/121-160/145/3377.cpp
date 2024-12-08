#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
		for(ll j=1LL*i*2;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int p10[6];
int dp[10101];
class Solution {
public:
    int minOperations(int n, int m) {
        cprime();
        divp[1]=1;
        int d=0,x=n;
        while(x) {
			d++;
			x/=10;
		}
		p10[0]=1;
		int i;
		FOR(i,5) p10[i+1]=p10[i]*10;
		FOR(i,p10[d]) dp[i]=1<<30;
		
		priority_queue<pair<int,int>> Q;
		if(divp[n]==0||divp[m]==0) return -1;
		dp[n]=n;
		Q.push({-n,n});
		
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			if(cur==m) return dp[cur];
			FOR(i,d) {
				int cd=cur/p10[i]%10;
				if(cd>1||(cd==1&&i!=d-1)) {
					int nex=cur-p10[i];
					if(divp[nex]&&chmin(dp[nex],co+nex)) Q.push({-dp[nex],nex});
				}
				if(cd<9) {
					int nex=cur+p10[i];
					if(divp[nex]&&chmin(dp[nex],co+nex)) Q.push({-dp[nex],nex});
				}
			}
			
			
		}
        return -1;
    }
};


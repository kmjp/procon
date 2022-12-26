#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
int N,K;
ll memo[101][10101];
ll pk[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	pk[0]=1;
	FOR(i,N+1) pk[i+1]=pk[i]*(K+1)%mo;
	
	memo[N+1][0]=1;
	ll ret=0;
	for(int cur=N;cur>=1;cur--) {
		ll tot=0;
		for(i=0;i<=10100;i++) {
			if(memo[cur+1][i]==0) break;
			tot+=memo[cur+1][i];
			FOR(j,K+1) {
				if(j>cur) {
					(memo[cur][i]+=memo[cur+1][i])%=mo;
					(ret+=(j+i)*pk[cur-1]%mo*memo[cur+1][i])%=mo;
				}
				else {
					(memo[cur][i+(j+i)/cur]+=memo[cur+1][i])%=mo;
					(ret+=(j+i)%cur*pk[cur-1]%mo*memo[cur+1][i])%=mo;
				}
			}
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

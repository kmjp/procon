#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,C,K;
int B[55][55];
const ll mo=1000000007;

ll dp[55][55];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C>>K;
	ll ret=0;
	
	vector<int> cand;
	cand.push_back(0);
	FOR(y,N) FOR(x,K) {
		cin>>B[y][x];
		cand.push_back(B[y][x]);
		(ret+=B[y][x]*modpow(K,N-1))%=mo;
	}
	sort(ALL(cand));
	
	for(x=1;x<=N*K;x++) {
		int dif=cand[x]-cand[x-1];
		if(dif==0) continue;
		ZERO(dp);
		dp[0][C]=1;
		FOR(i,N) {
			int lt=0,ge=0;
			FOR(j,K) {
				if(B[i][j]<cand[x]) lt++;
				else ge++;
			}
			FOR(j,C+1) {
				
				FOR(r,2) {
					int nlt=j+2*r,nge=(C-j)+2*(1-r);
					ll p=dp[i][j]*(r==0?ge:lt)%mo;
					if(p==0) continue;
					if(nlt&&nge) {
						(dp[i+1][nlt-1]+=p)%=mo;
					}
					else if(nlt==0) {
						(dp[i+1][nlt]+=p)%=mo;
						ret-=dif*p%mo*modpow(K,N-1-i)%mo;
					}
					else {
						(dp[i+1][nlt-2]+=p)%=mo;
					}
					
				}
			}
		}
		
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

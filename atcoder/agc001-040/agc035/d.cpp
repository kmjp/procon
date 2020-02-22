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

int N;
ll A[18];
vector<pair<ll,ll>> dp[18][18];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll L,R;
	cin>>L;
	N-=2;
	FOR(i,N) cin>>A[i];
	cin>>R;
	
	if(N==0) {
		cout<<L+R<<endl;
		return;
	}
	
	FOR(i,N) dp[i][1].push_back({A[i],A[i]});
	
	for(l=2;l<=N;l++) {
		for(x=0;x+l<=N;x++) {
			vector<pair<ll,ll>> R;
			
			for(y=x;y<x+l;y++) {
				if(y==x) {
					FORR(d,dp[x+1][l-1]) {
						R.push_back({d.first+A[y],d.first+A[y]+d.second});
					}
				}
				else if(y+1==x+l) {
					FORR(d,dp[x][l-1]) {
						R.push_back({d.first+A[y]+d.second,A[y]+d.second});
					}
				}
				else {
					FORR(d1,dp[x][y-x]) {
						FORR(d2,dp[y+1][x+l-(y+1)]) {
							R.push_back({d1.first+A[y]+d1.second+d2.first,d1.second+d2.first+A[y]+d2.second});
						}
					}
				}
			}
			
			sort(ALL(R));
			ll pre=1LL<<62;
			FORR(r,R) if(r.second<pre) {
				dp[x][l].push_back(r);
				pre=r.second;
			}
		}
		
	}
	
	ll ret=1LL<<62;
	FORR(d,dp[0][N]) ret=min(ret,d.first+d.second);
	cout<<ret+L+R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

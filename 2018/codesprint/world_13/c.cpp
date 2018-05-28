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

int T;
ll N,M,K;
ll A[101010];

ll modpow(ll a, ll n,ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		FOR(i,N) {
			cin>>A[i];
			A[i]%=M;
		}
		ll ret=0;
		if(K==0) {
			ret=1LL*N*(N+1)/2;
			int cnt=0;
			FOR(i,N) {
				if(A[i]==0) {
					cnt=0;
				}
				else {
					cnt++;
					ret-=cnt;
				}
			}
		}
		else {
			map<int,int> mp;
			ll cur=1;
			mp[K%M]=1;
			FOR(i,N) {
				if(A[i]==0) {
					mp.clear();
					cur=1;
				}
				else {
					cur=cur*A[i]%M;
					ret+=mp[cur];
				}
				mp[K*cur%M]++;
			}
		}
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

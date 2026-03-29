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

int N,M,L;
int V[18][18];

ll p2[202020];

const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<ll> fft_or(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(int m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				
				if(!rev) {
					v[j2]=(t1+t2)%mo;
				}
				else {
					v[j2]=(t2-t1+mo)%mo;
				}
				
			}
		}
	}
	return v;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,202010) p2[i+1]=p2[i]*2%mo;
	
	
	cin>>N>>M>>L;
	FOR(i,N) {
		cin>>x>>y;
		V[x-1][y-1-M]++;
	}
	int mask;
	vector<ll> F(1<<L);
	F[0]=1;
	
	FOR(i,M) {
		vector<ll> G(1<<L);
		G[0]=1;
		FOR(j,L) if(V[i][j]) {
			ll pat=p2[V[i][j]]-1;
			FOR(mask,1<<L) if(mask&(1<<j)) G[mask]=G[mask^(1<<j)]*pat%mo;
		}
		G[0]=0;
		
		vector<ll> F2=fft_or(F);
		vector<ll> G2=fft_or(G);
		FOR(mask,1<<L) (F2[mask]*=G2[mask])%=mo;
		F=fft_or(F2,1);
		F.resize(1<<L);
	}
	cout<<F[(1<<L)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

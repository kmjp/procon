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

int N,M;
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(int N,int M) {
	int i,x;
	
	if(M==1) return N;
	if(N<=2*(M-1)) return 0;
	
	int N2=((N+2)+M-1)/M-2;
	int low=N2+(N2+1)*(M-1);
	int add=N-low;
	
	ll ret=N2;
	ret=ret*modpow(N2+1,M-1-add)%mo;
	ret=ret*modpow(N2+2,add)%mo;
	/*
	cout<<N2;
	FOR(i,M-1-add) cout<<N2+1;
	FOR(i,add) cout<<N2+2;
	cout<<endl;
	
	vector<int> V(M);
	FOR(i,N) {
		V[0]++;
		sort(ALL(V));
		V[0]++;
		sort(ALL(V));
		FOR(x,M) if(V[x]) {
			V[x]--;
			break;
		}
		sort(ALL(V));
	}
	FORR(v,V) cout<<v;
	cout<<endl;
	*/
	return ret;
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=M;i++) cout<<hoge(N,i)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

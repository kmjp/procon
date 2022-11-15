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


int N,P,Q;
const ll mo=998244353;
int vis[202020];

void out(ll v) {
	cout<<v<<endl;
	exit(0);
}

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

int go1(int x) {
	if(x<P) return P-1-x;
	return x;
}
int go2(int x) {
	if(x>=N-Q) return N-1-(x-(N-Q));
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q;
	
	if(P==1) out((Q>1)+1);
	if(Q==1) out((P>1)+1);
	if(P==N&&Q==N) out(2);
	if(P==N||Q==N) out(4);
	if(P+Q<=N) out(4);
	
	map<ll,int> V;
	FOR(i,N) if(vis[i]==0) {
		x=i;
		int step=0;
		while(step==0||x!=i) {
			vis[x]=1;
			x=go1(x);
			x=go2(x);
			step+=2;
		}
		auto W=enumpr(step);
		FORR2(a,b,W) V[a]=max(V[a],b);
	}
	
	ll ret=1;
	FORR2(a,b,V) {
		FOR(x,b) ret=ret*a%mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

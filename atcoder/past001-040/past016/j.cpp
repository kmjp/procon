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

int N,K;
int A[202020];

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int g=0;
	FOR(i,K) {
		cin>>A[i];
		if(i) g=__gcd(g,A[i]-A[i-1]);
	}
	auto B=enumdiv(g);
	vector<ll> V;
	FORR(a,B) if(A[K-1]-A[0]<=a*(N-1)) V.push_back(a);
	cout<<V.size()<<endl;
	FORR(a,V) cout<<a<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

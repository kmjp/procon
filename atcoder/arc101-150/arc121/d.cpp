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

int N;
vector<ll> A;

ll hoge(vector<ll> V) {
	if(V.size()%2) return 1LL<<60;
	sort(ALL(V));
	ll ma=-1LL<<60;
	ll mi=1LL<<60;
	int i;
	FOR(i,V.size()/2) {
		ll a=V[i]+V[V.size()-1-i];
		ma=max(ma,a);
		mi=min(mi,a);
	}
	return ma-mi;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A.push_back(x);
	}
	ll mi=1LL<<60;
	mi=min(mi,hoge(A));
	FOR(i,N) {
		A.push_back(0);
		mi=min(mi,hoge(A));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

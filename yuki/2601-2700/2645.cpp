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

const ll DI=1000000;
double Hs[1010101];

ll N;

double H(ll v) {
	if(Hs[1]==0) {
		for(int i=1;i<=DI;i++) Hs[i]=Hs[i-1]+1.0/i;
	}
	if(v<=DI) return Hs[v];
	return Hs[DI]+log(v)-log(DI);
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double ret=0;
	ll cur=N;
	while(cur>0) {
		ll a=N/cur;
		ll nex=N/(a+1);
		ret+=H(a)*(H(cur)-H(nex));
		cur=nex;
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

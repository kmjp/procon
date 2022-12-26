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


ll N;
ll X[101010],Y[101010];
vector<pair<ll,ll>> ev;
multiset<ll> X1,Y1,X2,Y2;

int ok(ll v) {
	
	ll miy=1LL<<60,mix=1LL<<60;
	int i;
	FOR(i,N) {
		miy=min(miy,Y[i]);
		mix=min(mix,X[i]);
	}
	ll L=1LL<<60,R=-1LL<<60;
	ll D=1LL<<60,U=-1LL<<60;
	FOR(i,N) {
		if(X[i]-mix<=v&&Y[i]-miy<=v) continue;
		L=min(L,X[i]);
		R=max(R,X[i]);
		D=min(D,Y[i]);
		U=max(U,Y[i]);
	}
	
	return ((R-L)<=v&&(U-D)<=v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll xma=-1LL<<60,xmi=1LL<<60,yma=-1LL<<60,ymi=1LL<<60;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y;
		xma=max(xma,X[i]);
		xmi=min(xmi,X[i]);
		yma=max(yma,Y[i]);
		ymi=min(ymi,Y[i]);
	}
	
	if(N<=2) {
		cout<<0<<endl;
		return;
	}
	
	
	ll ret=(xma-xmi)+(yma-ymi);
	FOR(i,2) {
		ll can=1LL<<33;
		for(j=32;j>=0;j--) if(ok(can-(1LL<<j))) can-=1LL<<j;
		ret=min(ret,can);
		FOR(j,N) X[j]=-X[j];
	}
	cout<<ret/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

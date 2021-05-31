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

int N,Q;
ll X[101010],Y[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll pma=-1LL<<60,pmi=1LL<<60;
	ll mma=-1LL<<60,mmi=1LL<<60;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		pma=max(pma,X[i]+Y[i]);
		pmi=min(pmi,X[i]+Y[i]);
		mma=max(mma,X[i]-Y[i]);
		mmi=min(mmi,X[i]-Y[i]);
	}
	FOR(i,Q) {
		cin>>x;
		x--;
		ll ma=0;
		ma=max(ma,abs(pma-(X[x]+Y[x])));
		ma=max(ma,abs(pmi-(X[x]+Y[x])));
		ma=max(ma,abs(mma-(X[x]-Y[x])));
		ma=max(ma,abs(mmi-(X[x]-Y[x])));
		cout<<ma<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

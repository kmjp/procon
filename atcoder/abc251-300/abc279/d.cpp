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


ll A,B;

long double F(ll v) {
	long double ret=(long double)v*B;
	ret+=A/sqrt(1+v);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	ll X=0;
	for(i=61;i>=0;i--) {
		ll Y=X+(1LL<<i);
		if(F(Y)>F(Y+1)) X=Y;
	}
	long double mi=1e50;
	for(ll v=max(0LL,X-5);v<=X+5;v++) mi=min(mi,F(v));
	_P("%.12lf\n",(double)mi);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

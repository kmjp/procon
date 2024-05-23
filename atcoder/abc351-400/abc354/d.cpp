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

ll X1,Y1,X2,Y2;

ll hoge(int pat,ll y) {
	if(pat==0) return y/2*3+y%2*2;
	if(pat==1) return y/2*3+y%2;
	if(pat==2) return y/2;
	if(pat==3) return y/2+y%2;
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X1>>Y1>>X2>>Y2;
	
	ll pat[4]={};
	while((X2-X1)%4) {
		pat[(X1+(1LL<<40))%4]++;
		X1++;
	}
	FOR(i,4) pat[i]+=(X2-X1)/4;
	
	ll ret=0;
	FOR(i,4) {
		ll a=0;
		if(Y1>=0) a=hoge(i,Y2)-hoge(i,Y1);
		else if(Y2<=0) a=hoge(i^1,-Y1)-hoge(i^1,-Y2);
		else a=hoge(i,Y2)+hoge(i^1,-Y1);
		ret+=pat[i]*a;
		
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

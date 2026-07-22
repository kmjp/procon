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

int N,M;
int D[505050];
int ML,MR;

bitset<120000> now,ok;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i];
	ML=-1<<30,MR=1<<30;
	FOR(i,M) {
		cin>>x;
		if(x<=0) ML=max(ML,x);
		if(x>=0) MR=min(MR,x);
	}
	
	now[60000]=1;
	ok[60000]=1;
	FOR(i,min(60000,-ML)) ok[60000-i]=1;
	FOR(i,min(60000,MR)) ok[60000+i]=1;
	
	ll L=0,R=0;
	FOR(i,N) {
		x=D[i];
		if(x<0) now|=(now>>(-x));
		else now|=now<<x;
		now&=ok;
	}
	int ret=-1<<30;
	FOR(i,120000) if(now[i]) {
		ret=max(ret,i-60000);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

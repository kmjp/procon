#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll from[4020],to[4020];
ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	for(i=2;i<=N;i++) from[2000+i]=i-1;
	for(x=2;x<N;x++) {
		ZERO(to);
		for(y=1;y<=N;y++) to[2000+y-x+2]+=from[2000+y];
		FOR(y,4001) (to[y+1]+=to[y])%=mo;
		swap(from,to);
	}
	for(y=1;y<=N;y++) ret+=from[2000+y];
	
	ZERO(from);
	for(i=1;i<=N;i++) from[2000+i]=1;
	for(x=2;x<N;x++) {
		ZERO(to);
		for(y=1;y<=N;y++) to[2000+y-x+2]+=from[2000+y];
		FOR(y,4001) (to[y+1]+=to[y])%=mo;
		swap(from,to);
	}
	for(y=1;y<=N-1;y++) ret+=from[2000+y];
	
	
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

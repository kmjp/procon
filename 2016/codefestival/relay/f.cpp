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

int X;

int ng(ll v) {
	int i;
	FOR(i,X) {
		if(v%2) v=v/2;
		else v=(v-1)/2;
	}
	if(v>2) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>X;
	ll A=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ng(A-(1LL<<i))) A-=1LL<<i;
	cout<<(A-1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

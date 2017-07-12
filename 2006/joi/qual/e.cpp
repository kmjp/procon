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

ll N,K,M,R;
int D[101010];

void add(int v) {
	int cur=1;
	int i;
	
	FOR(i,10100) {
		D[i]+=cur/v;
		cur%=v;
		cur*=10;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M>>R;
	
	add(N);
	if(M==1) {
		for(i=1;i<N;i++) add(N*i);
	}
	
	for(i=10099;i>=1;i--) {
		D[i-1]+=D[i]/10;
		D[i]%=10;
	}
	
	_P("%d.",D[0]);
	for(i=1;i<=R;i++) {
		_P("%d",D[i]);
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

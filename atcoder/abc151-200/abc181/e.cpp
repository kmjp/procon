#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int H[202020],W[202020];
ll S[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>H[i];
	}
	sort(H,H+N);
	FOR(i,N) {
		S[0][i+1]=S[0][i];
		S[1][i+1]=S[1][i];
		S[i%2][i+1]+=H[i];
	}
	FOR(i,M) cin>>W[i];
	sort(W,W+M);
	
	ll ret=1LL<<60;
	FOR(i,N) {
		ll p=S[1][i]+S[0][N]-S[0][i+1];
		ll m=S[0][i]+S[1][N]-S[1][i+1];
		x=lower_bound(W,W+M,H[i])-W;
		if(x<M) ret=min(ret,p-m+abs(H[i]-W[x]));
		x--;
		if(x>=0) ret=min(ret,p-m+abs(H[i]-W[x]));
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

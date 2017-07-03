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

int H,W;
int H2,W2;
ll A[1002][1002];
ll S[1002][1002];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>W2>>H2;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		if(A[y][x]==-1) A[y][x]=1LL<<40;
	}
	FOR(y,H) FOR(x,W) {
		S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+A[y][x];
	}
	
	ll mi=1LL<<60;
	FOR(y,H-H2+1) FOR(x,W-W2+1) {
		
		mi=min(mi,S[y+H2][x+W2]-S[y][x+W2]-S[y+H2][x]+S[y][x]);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}


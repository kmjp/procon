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

int A,B,C,D,E,F;

int W[3030];
int S[3030];


void solve() {
	int i,j,k,l,r,x,y;;
	
	cin>>A>>B>>C>>D>>E>>F;
	W[0]=S[0]=1;
	FOR(i,3001) if(W[i]) {
		if(i+100*A<=F) W[i+100*A]=1;
		if(i+100*B<=F) W[i+100*B]=1;
	}
	FOR(i,3001) if(S[i]) {
		if(i+C<=F) S[i+C]=1;
		if(i+D<=F) S[i+D]=1;
	}
	
	int v=0,s=0;
	FOR(x,3001) FOR(y,3001) if(W[x] && S[y]) {
		if(x/100*E<y) continue;
		if(x+y>F) continue;
		if(y*v>=s*(x+y)) s=y,v=x+y;
	}
	cout<<v<<" "<<s<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

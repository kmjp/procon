#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll C[10],D[10];
int can[7];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	FOR(i,7) cin>>C[i];
	if(C[0]==0) return _P("NO\n");
	C[0]--;
	
	D[0]=C[0]-C[6]+C[5]-C[4]+C[3]-C[2]+C[1];
	for(i=1;i<=6;i++) D[i]=2*C[i]-D[i-1];
	FOR(i,7) if(D[i]<0) return _P("NO\n");
	
	can[0]=1;
	for(i=1;i<=6;i++) {
		if(D[i-1]==0) break;
		can[i]=1;
	}
	for(i=6;i>=1;i--) {
		if(D[i]==0) break;
		can[i]=1;
	}
	FOR(i,7) if(C[i] && can[i]==0) return _P("NO\n");
	return _P("YES\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int NA,NB;
ll A[101000],B[101000];
set<ll> S,S2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>NA>>NB;
	FOR(i,NA) cin>>A[i],S.insert(A[i]);
	FOR(i,NB) cin>>B[i],S.insert(B[i]);
	sort(A,A+NA);
	sort(B,B+NB);
	
	int tot=0;
	for(x=0,y=0;x<NA && y<NB;) {
		if(A[x]==B[y]) {
			tot++;
			x++;
			y++;
		}
		else if(A[x]<B[y]) x++;
		else y++;
	}
	
	_P("%.12lf\n",1.0*tot/S.size());
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

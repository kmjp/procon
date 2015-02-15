#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
int L,Q,ok[2001][2001];
ll num[2001][2001];

ll dodo(int l,int r) {
	if(r<l) return 0;
	ll& ret=num[l][r];
	if(ret>=0) return ret;
	
	ret=(ok[l][r])?(r-l):0;
	ret+=dodo(l+1,r)+dodo(l,r-1)-dodo(l+1,r-1);
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	L=S.size();
	FOR(x,L) for(y=1;y<=L;y++) if(x+2*y<=L) {
		ok[x][x+2*y]=1;
		FOR(z,y) if(S[x+z]!=S[x+y+z]) ok[x][x+2*y]=0;
	}
	MINUS(num);
	dodo(0,L);
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		cout<<dodo(x-1,y)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

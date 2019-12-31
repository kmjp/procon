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


int L;
string S;

// ‘O‚©‚çŒŸõ
int dpdp[111][111];
int lcs(string& AA,string& BB) {
	int x,y,ma=0;
	ZERO(dpdp);
	
	FOR(x,AA.size()) FOR(y,BB.size()) {
		if(AA[x]==BB[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
		ma=max(ma,dpdp[x+1][y+1]);
	}
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>S;
	int mi=L;
	for(x=1;x<=L-1;x++) {
		string a=S.substr(0,x), b=S.substr(x);
		mi=min(mi, L-2*lcs(a,b));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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

int H,W,K,P;
int ID[40][40];
string S[50];
ll pat[50][50];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>P;
	MINUS(ID);
	FOR(i,K) {
		cin>>x>>y>>S[i];
		ID[x][y]=i;
	}
	
	ll ma=0;
	int tmask=-1;
	
	for(int mask=0;mask<1<<K;mask++) {
		if(__builtin_popcount(mask)>P) continue;
		ZERO(pat);
		pat[0][0]=1;
		FOR(x,H+1) FOR(y,W+1) if(x||y) {
			if(ID[x][y]>=0 && (mask&(1<<ID[x][y]))==0) continue;
			if(x) pat[x][y]+=pat[x-1][y];
			if(y) pat[x][y]+=pat[x][y-1];
		}
		if(pat[H][W]>ma) {
			ma=pat[H][W];
			tmask=mask;
		}
	}
	
	if(tmask==-1) return _P("0\n");
	cout<<ma%mo<<endl;
	FOR(i,K) if(tmask&(1<<i)) cout<<S[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

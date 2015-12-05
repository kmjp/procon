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

int Q;
string S,T;

void solve() {
	int i,j,k,l,r,x,y,s;
	
	cin>>Q;
	while(Q--) {
		cin>>S>>T;
		int LS=S.size(),LT=T.size();
		FORR(r,S) r-='a';
		FORR(r,T) r-='a';
		
		int ok=0;
		FOR(s,LS) if(S[s]==T[0]) {
			y=0;
			int pat[26]={};
			int ok2=1;
			for(x=s;x<LS && y<LT;x++) {
				if(pat[S[x]]==0) pat[S[x]]=2-(S[x]==T[y]);
				if(pat[S[x]]==1) {
					if(S[x]!=T[y]) {
						ok2=0;
						break;
					}
					y++;
				}
				if(pat[S[x]]==2) {
					if(S[x]==T[y]) {
						ok2=0;
						break;
					}
				}
			}
			if(ok2 && y>=LT) ok=1;
		}
		
		if(ok) _P("YES\n");
		else _P("NO\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

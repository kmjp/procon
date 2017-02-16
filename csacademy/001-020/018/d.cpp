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

string S,T;
int NS,NT;
int nex[201010][26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	S=S+S;
	NS=S.size();
	NT=T.size();
	FOR(i,26) nex[NS-1][i]=200010;
	for(i=NS-2;i>=0;i--) {
		FOR(x,26) {
			nex[i][x] = nex[i+1][x];
			if(S[i+1]==x+'a') nex[i][x]=i+1;
		}
	}
	
	NS/=2;
	ll cur=NS-1;
	FORR(c,T) {
		if(nex[cur%NS][c-'a']>200000) return _P("-1\n");
		cur += nex[cur%NS][c-'a'] - cur%NS;
	}
	
	cout<<cur/NS<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

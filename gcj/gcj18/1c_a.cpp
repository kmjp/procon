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

int T,testcase;
int N,L;
string S[2020];
set<string> SS;
set<char> C[2020];
map<string,int> pref[11];

string ret;

void dfs(int cur,string s) {
	if(cur==L) {
		if(SS.count(s)==0) ret=s;
		return;
	}
	int mi=101010;
	char be='0';
	FORR(c,C[cur]) {
		if(pref[cur+1][s+c]<mi) {
			mi=pref[cur+1][s+c];
			be=c;
		}
	}
	s+=be;
	dfs(cur+1,s);
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>L;
	SS.clear();
	FOR(i,L) C[i].clear();
	FOR(i,L+1) pref[i].clear();
	
	ret="";
	FOR(i,N) {
		cin>>S[i];
		SS.insert(S[i]);
		FOR(j,L) {
			C[j].insert(S[i][j]);
			pref[j+1][S[i].substr(0,j+1)]++;
		}
	}
	
	dfs(0,"");
	
	if(ret.empty()) _P("Case #%d: -\n",TC);
	else _P("Case #%d: %s\n",TC,ret.c_str());
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}

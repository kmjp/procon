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

int X,Y;
set<pair<int,int> > S[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	S[0].insert({0,0});
	FOR(i,3) {
		FORR(r,S[i]) {
			S[i+1].insert({r.first-2,r.second-1});
			S[i+1].insert({r.first-2,r.second+1});
			S[i+1].insert({r.first-1,r.second-2});
			S[i+1].insert({r.first-1,r.second+2});
			S[i+1].insert({r.first+1,r.second-2});
			S[i+1].insert({r.first+1,r.second+2});
			S[i+1].insert({r.first+2,r.second-1});
			S[i+1].insert({r.first+2,r.second+1});
		}
	}
	FOR(i,4) if(S[i].count({X,Y})) return _P("YES\n");
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

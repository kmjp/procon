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

int H,W;
string S[101];
vector<pair<int,int>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='*') V.push_back({y,x});
	}
	
	if(V[0].first==V[1].first) {
		if(V[0].first==0) S[V[0].first+1][V[0].second]='*';
		else S[V[0].first-1][V[0].second]='*';
	}
	else if(V[0].second==V[1].second) {
		if(V[0].second==0) S[V[0].first][V[0].second+1]='*';
		else S[V[0].first][V[0].second-1]='*';
	}
	else {
		S[V[0].first][V[1].second]='*';
	}
	
	FOR(y,H) cout<<S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

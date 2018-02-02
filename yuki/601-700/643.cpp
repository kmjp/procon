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

int X,Y;

map<pair<int,int>,int> M;

int dfs(int X,int Y) {
	if(X==Y) return 0;
	if(M.count({X,Y})) return M[{X,Y}];
	M[{X,Y}]=101010;
	if(abs(X)>200 || abs(Y)>200) return 1010101;
	M[{X,Y}]=1+min(dfs(Y,X),dfs(X+Y,X-Y));
	return M[{X,Y}];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	x=dfs(X,Y);
	if(x>=1000) x=-1;
	cout<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

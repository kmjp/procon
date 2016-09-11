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

set<pair<int,int>> S;
set<pair<int,int>> S2;
ll H,W,N;
ll A[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>x>>y;
		S.insert({x,y});
		FOR(j,3) FOR(k,3) S2.insert({x-j,y-k});
	}
	
	A[0]=(H-2)*(W-2);
	FORR(r,S2) {
		x = r.first;
		y = r.second;
		if(x<=0 || x+2>H) continue;
		if(y<=0 || y+2>W) continue;
		int ret=0;
		FOR(j,3) FOR(k,3) ret += S.count({x+j,y+k});
		
		A[ret]++;
		A[0]--;
		
	}
	FOR(i,10) cout<<A[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

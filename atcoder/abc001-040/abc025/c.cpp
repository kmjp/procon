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

int B[4][4],C[4][4];
int T[3][3];

pair<int,int> calc() {
	int y,x;
	pair<int,int> p={0,0};
	FOR(y,2) FOR(x,3) {
		if(T[y][x]==T[y+1][x]) p.first += B[y][x];
		else p.second += B[y][x];
	}
	FOR(y,3) FOR(x,2) {
		if(T[y][x]==T[y][x+1]) p.first += C[y][x];
		else p.second += C[y][x];
	}
	return p;
}



pair<int,int> dodo(int t) {
	pair<int,int> p={-1,-1};
	int y,x;
	int did=0;
	
	FOR(y,3) FOR(x,3) if(T[y][x]==0) {
		did=1;
		T[y][x]=t;
		pair<int,int> res=dodo(3-t);
		
		if(t==1 && res.first>p.first) p=res;
		if(t==2 && res.second>p.second) p=res;
		T[y][x]=0;
	}
	
	if(did==0) return calc();
	return p;
}



void solve() {
	int i,j,k,l,x,y; string s;
	
	FOR(i,3) cin>>B[0][i];
	FOR(i,3) cin>>B[1][i];
	FOR(i,2) cin>>C[0][i];
	FOR(i,2) cin>>C[1][i];
	FOR(i,2) cin>>C[2][i];
	
	pair<int,int> r=dodo(1);
	_P("%d\n%d\n",r.first,r.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

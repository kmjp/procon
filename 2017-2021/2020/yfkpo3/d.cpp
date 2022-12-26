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

int gr[1010][1010];

int grundy(int x,int y) {
	if(gr[x][y]>=0) return gr[x][y];
	set<int> S;
	int i;
	if(x) FOR(i,y+1) S.insert(grundy(x-1,i));
	FOR(i,y) S.insert(grundy(x,i));
	i=0;
	while(S.count(i)) i++;;
	return gr[x][y]=i;
}

int grundy2(int x,int y) {
	if(x<=y) return x+y;
	return 2*y+(y%2!=x%2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	
	MINUS(gr);
	FOR(y,20) {
		FOR(x,20) _P("%2d ",grundy(x,y)==grundy2(x,y));
		_P("\n");
	}
	*/
	
	int nim=0;
	int N;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		nim^=grundy2(x,y);
	}
	if(nim) cout<<"matsu"<<endl;
	else cout<<"prd"<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int ask(char c) {
	string s;
	cout<<c<<endl;
	cin>>s;
	if(s[0]=='M') exit(0);
	return atoi(s.c_str());
}

int vis[50][50];

int dfs(int cy,int cx,int d) {
	int i,x;
	vis[cy][cx]=1;
	
	FOR(i,4) {
		int dx[4]={1,0,-1,0};
		int dy[4]={0,1,0,-1};
		
		x=ask('R');
		while(x>100) ask('F');
		
		d=(d+1)%4;
		int tx=cx+dx[d];
		int ty=cy+dy[d];
		
		if(x>0 && vis[ty][tx]==0) ask('F'), dfs(ty,tx,d);
	}
	ask('B');
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	dfs(25,25,1);
}


int main(int argc,char** argv){
	string s;int i;
	//if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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
string S[1010];
string T[2];

int isjoi(int y,int x) {
	if(x<0 || y<0 || x+1>=W || y+1>=H) return 0;
	if(S[y][x]!=T[0][0]) return 0;
	if(S[y][x+1]!=T[0][1]) return 0;
	if(S[y+1][x]!=T[1][0]) return 0;
	if(S[y+1][x+1]!=T[1][1]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	cin>>T[0]>>T[1];
	
	int cur=0;
	FOR(y,H) FOR(x,W) cur+=isjoi(y,x);
	
	int ma=cur;
	FOR(y,H) FOR(x,W) {
		char c=S[y][x];
		int tmp=cur - (isjoi(y-1,x-1)+isjoi(y-1,x)+isjoi(y,x-1)+isjoi(y,x));
		S[y][x]='J';
		ma=max(ma,tmp+isjoi(y-1,x-1)+isjoi(y-1,x)+isjoi(y,x-1)+isjoi(y,x));
		S[y][x]='O';
		ma=max(ma,tmp+isjoi(y-1,x-1)+isjoi(y-1,x)+isjoi(y,x-1)+isjoi(y,x));
		S[y][x]='I';
		ma=max(ma,tmp+isjoi(y-1,x-1)+isjoi(y-1,x)+isjoi(y,x-1)+isjoi(y,x));
		S[y][x]=c;
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

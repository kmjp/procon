#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int R,C,K;
string S[1010];
int sum[1010][1010];
int ret=0,ss;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>C>>K;
	FOR(y,R) {
		cin>>S[y];
		FOR(x,C) sum[y][x+1]=sum[y][x]+(S[y][x]=='o');
	}
	
	ss=1;
	for(i=2;i<=K;i++) ss+=(i-1)*4;
	
	FOR(y,R) FOR(x,C) {
		if(y<K-1 || y+K-1>=R) continue;
		if(x<K-1 || x+K-1>=C) continue;
		int st=0;
		for(i=-(K-1);i<=(K-1);i++) st+=sum[y+i][x+(K-1-abs(i))+1]-sum[y+i][x-(K-1-abs(i))];
		if(st==ss) ret++;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

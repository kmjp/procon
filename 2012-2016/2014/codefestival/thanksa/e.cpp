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

int R,C,M,N;
int G[102][102];
int RR[2][10000],CC[2][10000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>C>>M>>N;
	FOR(i,N) {
		cin>>RR[0][i]>>RR[1][i]>>CC[0][i]>>CC[1][i];
		RR[0][i]--;
		RR[1][i]--;
		CC[0][i]--;
		CC[1][i]--;
		for(y=RR[0][i];y<=RR[1][i];y++) for(x=CC[0][i];x<=CC[1][i];x++) G[y][x]++;
	}
	
	FOR(i,N) {
		for(y=RR[0][i];y<=RR[1][i];y++) for(x=CC[0][i];x<=CC[1][i];x++) G[y][x]--;
		j=0;
		FOR(y,R) FOR(x,C) j+=G[y][x]%4==0;
		if(j==M) cout<<i+1<<endl;
		for(y=RR[0][i];y<=RR[1][i];y++) for(x=CC[0][i];x<=CC[1][i];x++) G[y][x]++;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

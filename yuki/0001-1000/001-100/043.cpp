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

int N;
string S[6];
vector<pair<int,int> > P;

int best() {
	int w0=0,win[7],x,y;
	
	ZERO(win);
	FOR(x,6) w0+=(S[0][x]=='o');
	for(x=1;x<N;x++) {
		int w=0;
		FOR(y,N) w+=(S[x][y]=='o');
		win[w]=1;
	}
	y=1;
	for(x=6;x>w0;x--) y+=win[x];
	return y;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,6) cin>>S[i];
	FOR(i,N) for(j=i+1;j<N;j++) if(S[i][j]=='-') P.push_back(make_pair(i,j));
	
	int mi=N;
	for(int mask=0;mask < 1<<P.size(); mask++) {
		FOR(j,P.size()) {
			if(mask&(1<<j)) S[P[j].first][P[j].second]='o',S[P[j].second][P[j].first]='x';
			else S[P[j].first][P[j].second]='x',S[P[j].second][P[j].first]='o';
		}
		mi=min(mi,best());
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

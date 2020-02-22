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
int D[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='#') {
				D[y][x]=0;
				Q.push(y*1000+x);
			}
			else {
				D[y][x]=0;
			}
		}
	}
	
	int ma=0;
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		ma=max(ma,D[cy][cx]);
		Q.pop();
		FOR(i,4) {
			int dd[4]={0,1,0,-1};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			S[ty][tx]='#';
			D[ty][tx]=D[cy][cx]+1;
			Q.push(ty*1000+tx);
		}
		
		
	}
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

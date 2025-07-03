#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W,SY,SX,GY,GX;
string S[55];
int D[55][55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) D[y][x]=101010;
	D[SY][SX]=0;
	queue<int> Q;
	Q.push(SY*100+SX);
	while(Q.size()) {
		int cy=Q.front()/100;
		int cx=Q.front()%100;
		Q.pop();
		int d[4]={0,1,0,-1};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(S[ty][tx]=='#'||D[ty][tx]!=101010) continue;
			D[ty][tx]=D[cy][cx]+1;
			Q.push(ty*100+tx);
		}
	}
	cout<<D[GY][GX]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

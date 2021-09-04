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


int H,W;
string S[505];
int D[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) D[y][x]=1<<20;
	}
	D[0][0]=0;
	deque<int> Q;
	Q.push_back(0);
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop_front();
		
		int d[4]={0,1,0,-1};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(D[ty][tx]>D[cy][cx]) {
				D[ty][tx]=D[cy][cx];
				Q.push_front(ty*1000+tx);
			}
		}
		for(int dy=-2;dy<=2;dy++) {
			for(int dx=-2;dx<=2;dx++) {
				if(abs(dy)+abs(dx)==4) continue;
				int ty=cy+dy;
				int tx=cx+dx;
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push_back(ty*1000+tx);
				}
			}
		}
	}
	cout<<D[H-1][W-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

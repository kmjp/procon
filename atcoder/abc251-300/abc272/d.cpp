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

int N,M;
vector<pair<int,int>> C;

int D[400][400];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(x=0;x<=1000;x++) for(y=0;y<=1000;y++) {
		if(x*x+y*y==M) {
			C.push_back({x,y});
			C.push_back({x,-y});
			C.push_back({-x,y});
			C.push_back({-x,-y});
		}
	}
	FOR(y,N) FOR(x,N) D[y][x]=1<<20;
	D[0][0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cy=Q.front()/400;
		int cx=Q.front()%400;
		Q.pop();
		FORR2(dx,dy,C) {
			int ty=cy+dy;
			int tx=cx+dx;
			if(tx>=0&&tx<N&&ty>=0&&ty<N&&D[ty][tx]==1<<20) {
				D[ty][tx]=D[cy][cx]+1;
				Q.push(ty*400+tx);
			}
		}
	}
	FOR(y,N) {
		FOR(x,N) {
			if(D[y][x]==1<<20) D[y][x]=-1;
			cout<<D[y][x]<<" ";
		}
		cout<<endl;
	}
			
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

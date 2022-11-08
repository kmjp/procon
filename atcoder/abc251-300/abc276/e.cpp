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
string S[1010101];
vector<int> D[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int SY,SX;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='S') {
			SY=y;
			SX=x;
			S[y][x]='#';
		}
		D[y].resize(W);
	}
	
	int d[4]={0,1,0,-1};
	FOR(i,4) {
		FOR(y,H) FOR(x,W) D[y][x]=0;
		int ty=SY+d[i];
		int tx=SX+d[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
		D[ty][tx]=1;
		queue<int> Q;
		Q.push(ty*W+tx);
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop();
			FOR(j,4) {
				int ty=cy+d[j];
				int tx=cx+d[j^1];
				if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
				if(D[ty][tx]==0) {
					D[ty][tx]=1;
					Q.push(ty*W+tx);
				}
			}
		}
		FOR(j,4) if(i!=j) {
			int sy=SY+d[j];
			int sx=SX+d[j^1];
			if(sy<0||sy>=H||sx<0||sx>=W||S[sy][sx]=='#') continue;
			if(D[sy][sx]) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

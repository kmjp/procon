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
string S[2020];
int D[2020][2020];
int SX,SY,GX,GY;
vector<pair<int,int>> C[26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			D[y][x]=1<<30;
			if(S[y][x]=='S') SX=x,SY=y,S[y][x]='.';
			if(S[y][x]=='G') GX=x,GY=y,S[y][x]='.';
			if(S[y][x]>='a'&&S[y][x]<='z') C[S[y][x]-'a'].push_back({y,x});
		}
	}
	D[SY][SX]=0;
	queue<pair<int,int>> Q;
	Q.push({SY,SX});
	while(Q.size()) {
		auto p=Q.front();
		int cy=p.first;
		int cx=p.second;
		Q.pop();
		if(S[cy][cx]>='a'&&S[cy][cx]<='z') {
			FORR2(ty,tx,C[S[cy][cx]-'a']) {
				if(D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push({ty,tx});
				}
			}
			C[S[cy][cx]-'a'].clear();
		}
		
		FOR(i,4) {
			int d[4]={0,1,0,-1};
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(tx<0||tx>=W||ty<0||ty>=H) continue;
			if(S[ty][tx]=='#') continue;
			if(D[ty][tx]>D[cy][cx]+1) {
				D[ty][tx]=D[cy][cx]+1;
				Q.push({ty,tx});
			}
		}
	}
	
	if(D[GY][GX]==1<<30) {
		cout<<-1<<endl;
	}
	else {
		cout<<D[GY][GX]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

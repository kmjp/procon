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
string S[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='.') Q.push(y*W+x);
	}
	while(Q.size()) {
		queue<int> Q2;
		vector<int> V;
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop();
			if(cy<0||cy>=H||cx<0||cx>=W) continue;
			if(S[cy][cx]=='#') continue;
			int num=0;
			int d[]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				num+=S[ty][tx]=='#';
			}
			if(num==1) {
				V.push_back(cy*W+cx);
				if(cy) Q2.push((cy-1)*W+cx);
				if(cy+1<H) Q2.push((cy+1)*W+cx);
				if(cx) Q2.push(cy*W+cx-1);
				if(cx+1<W) Q2.push(cy*W+cx+1);
			}
		}
		FORR(v,V) S[v/W][v%W]='#';
		swap(Q,Q2);
	}
	int ret=0;
	FOR(y,H) FORR(c,S[y]) if(c=='#') ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

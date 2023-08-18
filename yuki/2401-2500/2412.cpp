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
string S[2424];
int ok[2424][2424];
int D[2424][2424];

int hoge() {
	int y,x,dy,dx;
	FOR(y,H-2) FOR(x,W-2) {
		D[y][x]=0;
		ok[y][x]=1;
		for(dy=y;dy<=y+2;dy++) for(dx=x;dx<=x+2;dx++) if(S[dy][dx]=='#') ok[y][x]=0;
	}
	D[0][0]=1;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cy=Q.front()/10000;
		int cx=Q.front()%10000;
		Q.pop();
		if(cy==H-3&&cx==W-3) return 0;
		for(y=cy-1;y<=cy+1;y++) for(x=cx-1;x<=cx+1;x++) {
			if(x<0||x>W-3||y<0||y>H-3) continue;
			if(ok[y][x]==0) continue;
			if(D[y][x]==1) continue;
			D[y][x]=1;
			Q.push(y*10000+x);
		}
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	if(hoge()) {
		cout<<0<<endl;
		return;
	}
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if(y<=2&&x<=2) continue;
		if(y>=H-3&&x>=W-3) continue;
		S[y][x]='#';
		if(hoge()) {
			cout<<1<<endl;
			return;
		}
		S[y][x]='.';
	}
	cout<<2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

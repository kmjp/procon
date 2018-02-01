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

pair<int,int> A[303][303],B[303][303],C[303][303];

void dfs(int H,int W) {
	int x,y;
	if(H==2 && W>2) {
		int cy=0,cx=0;
		FOR(x,W) {
			A[cy][cx]={0,x};
			cx+=2;
			if(cx>=W) cx%=W, cy^=1;
		}
		cy=1,cx=W-1;
		FOR(x,W) {
			A[cy][cx]={1,x};
			cx+=2;
			if(cx>=W) cx%=W, cy^=1;
		}
	}
	else if(H>2 && W==2) {
		int cy=0,cx=0;
		FOR(y,H) {
			A[cy][cx]={y,0};
			cy+=2;
			if(cy>=H) cy%=H, cx^=1;
		}
		cy=H-1,cx=1;
		FOR(y,H) {
			A[cy][cx]={y,1};
			cy+=2;
			if(cy>=H) cy%=H, cx^=1;
		}
	}
	else if(H>1 && W>1) {
		H/=2,W/=2;
		dfs(H,W);
		FOR(y,H) FOR(x,W) {
			A[y+H][x+W]={A[y][x].first,A[y][x].second+W};
			A[y+H][x]={A[y][x].first+H,A[y][x].second+W};
			A[y][x+W]={A[y][x].first+H,A[y][x].second};
		}
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>H>>W;
	
	if((H+W)%2==1) return _P("0\n");
	
	int X=1,Y=1;
	while(H%(Y*2)==0) Y*=2;
	while(W%(X*2)==0) X*=2;
	
	dfs(Y,X);
	int S=H/Y,T=W/X,s,t;
	FOR(s,S) FOR(t,T) B[s][t]={s,t};
	//yoko
	FOR(s,S) {
		vector<pair<int,int>> V;
		FOR(t,T) V.push_back(B[s][t]);
		FOR(t,T) B[s][t*2%T]=V[t];
	}
	//tate
	FOR(t,T) {
		vector<pair<int,int>> V;
		FOR(s,S) V.push_back(B[s][t]);
		FOR(s,S) B[s*2%S][t]=V[s];
	}
	
	FOR(s,S) FOR(t,T) {
		FOR(y,Y) FOR(x,X) {
			C[s*Y+y][t*X+x].first=A[y][x].first + B[s][t].first*Y;
			C[s*Y+y][t*X+x].second=A[y][x].second + B[s][t].second*X;
		}
	}
	_P("1\n");
	FOR(y,H) {
		FOR(x,W) _P("%d %d%c",1+C[y][x].first,1+C[y][x].second,(x==W-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

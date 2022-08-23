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
string G[505];
int vis[505][505];

int cy,cx;
void out() {
	cout<<cy+1<<" "<<cx+1<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>G[y];
	
	while(1) {
		if(vis[cy][cx]) {
			cout<<-1<<endl;
			return;
		}
		vis[cy][cx]=1;
		if(G[cy][cx]=='L') {
			if(cx==0) out();
			cx--;
		}
		else if(G[cy][cx]=='R') {
			if(cx==W-1) out();
			cx++;
		}
		else if(G[cy][cx]=='U') {
			if(cy==0) out();
			cy--;
		}
		else {
			if(cy==H-1) out();
			cy++;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

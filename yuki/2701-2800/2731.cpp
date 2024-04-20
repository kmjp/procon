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
int A[1010][1010];
int C[1010][1010];
set<pair<int,int>> X[2];

int step;

void add(int y,int x) {
	int i;
	int c=step%2;
	C[y][x]=c;
	FOR(i,4) {
		int d[]={0,1,0,-1};
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(C[ty][tx]!=-1&&C[ty][tx]!=C[y][x]) {
			cout<<step-2<<endl;
			exit(0);
		}
		if(C[ty][tx]==-1) X[c].insert({A[ty][tx],ty*1000+tx});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	MINUS(C);
	step=1;
	add(0,0);
	step=2;
	add(H-1,W-1);

	while(1) {
		step++;
		auto p=*X[step%2].begin();
		X[step%2].erase(X[step%2].begin());
		add(p.second/1000,p.second%1000);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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


int N;
int A[16][16];
int ret=0;

void dfs(int mask,int v) {
	if(mask==(1<<(2*N))-1) {
		ret=max(ret,v);
		return;
	}
	int x,y;
	FOR(x,2*N) if((mask&(1<<x))==0) break;
	FOR(y,2*N) if(y>x&&(mask&(1<<y))==0) {
		dfs(mask|(1<<x)|(1<<y),v^A[x][y]);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,2*N) {
		for(y=x+1;y<2*N;y++) cin>>A[x][y];
	}
	dfs(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

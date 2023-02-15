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

int T;
int N;
ll TW,W[105],F[107];
ll ret;

void dfs(int cur,ll TW,ll V) {
	ret=max(ret,V);
	if(cur==0) return;
	if(W[cur]>TW) {
		dfs(cur-1,TW,V);
	}
	else {
		dfs(cur-1,TW-W[cur],V+F[cur]);
		//スキップしてもいいケース
		if(cur>=2&&TW<W[cur]+W[cur-1]&&TW>=W[cur-1]&&V+F[cur+1]-2>ret) {
			dfs(cur-1,TW,V);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[1]=1;
	F[2]=2;
	for(i=3;i<=100;i++) F[i]=F[i-1]+F[i-2];
	
	cin>>T;
	while(T--) {
		cin>>N>>TW;
		for(i=1;i<=N;i++) cin>>W[i];
		ret=0;
		dfs(N,TW,0);
		cout<<ret<<endl;
	}
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

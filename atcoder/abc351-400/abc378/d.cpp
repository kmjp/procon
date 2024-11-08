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

int H,W,K;
string S[11];
int ret;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

void dfs(int cy,int cx,int K) {
	if(cy<0||cy>=H||cx<0||cx>=W) return;
	if(S[cy][cx]=='#') return;
	S[cy][cx]='#';
	if(K==0) {
		ret++;
	}
	else {
		int i;
		FOR(i,4) dfs(cy+dy[i],cx+dx[i],K-1);
	}
	S[cy][cx]='.';
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	int mask;
	
	FOR(y,H) FOR(x,W) dfs(y,x,K);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

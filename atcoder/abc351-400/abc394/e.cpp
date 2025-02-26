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
string S[101];
int E[101][101];
vector<pair<int,int>> C[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	priority_queue<pair<int,int>> Q;
	FOR(y,N) FOR(x,N) {
		E[y][x]=1<<20;
		if(y==x) E[y][x]=0;
		else if(S[y][x]!='-') E[y][x]=1;
		
		Q.push({-E[y][x],y*100+x});
	}
	while(Q.size()) {
		int co=-Q.top().first;
		int c1=Q.top().second/100;
		int c2=Q.top().second%100;
		Q.pop();
		if(E[c1][c2]!=co) continue;
		FOR(x,N) FOR(y,N) if(S[x][c1]==S[c2][y]&&S[x][c1]!='-'&&chmin(E[x][y],co+2)) Q.push({-E[x][y],x*100+y});
	}
	
	FOR(y,N) {
		FOR(x,N) {
			if(E[y][x]>1000) E[y][x]=-1;
			cout<<E[y][x]<<" ";
		}
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

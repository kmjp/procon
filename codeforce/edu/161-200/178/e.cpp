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

int N,K;
string S;
int Q;
int nex[1<<20][26];
int need[1<<20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,K) {
		nex[N][i]=N;
	}
	FOR(j,K) {
		for(i=N-1;i>=0;i--) {
			nex[i][j]=nex[i+1][j];
			if(S[i]=='a'+j) nex[i][j]=i;
		}
	}
	need[N]=1;
	for(i=N-1;i>=0;i--) {
		need[i]=1<<20;
		FOR(j,K) need[i]=min(need[i],need[nex[i][j]+1]+1);
	}
	cin>>Q;
	while(Q--) {
		cin>>s;
		int cur=0;
		FORR(c,s) {
			if(cur<N) cur=nex[cur][c-'a']+1;
			else cur=N+1;
		}
		cout<<need[cur]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N,Q;
int NC[303030];
int pre[606060];
int nex[606060];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) {
		pre[i]=0;
		nex[i]=N+i;
		pre[N+i]=i;
		nex[N+i]=N+i;
	}
	while(Q--) {
		cin>>x>>y;
		k=nex[x];
		pre[k]=0;
		nex[x]=y;
		pre[y]=x;
	}
	
	FOR(i,N) {
		int cur=N+i+1;
		int ret=-1;
		while(cur) ret++,cur=pre[cur];
		cout<<ret<<" ";
	}
	cout<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

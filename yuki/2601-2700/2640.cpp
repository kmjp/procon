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

int N,M,K;
ll E[202][202];

int S[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(x,N) FOR(y,N) E[y][x]=(x==y)?0:1LL<<60;
	FOR(i,K+1) {
		cin>>S[i];
		S[i]--;
	}
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1][y-1]=E[y-1][x-1]=k;
	}
		
	
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	FOR(i,K) {
		bt.add(i+1,E[S[i+1]][S[i]]);
	}
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			if(x) bt.add(x,-E[S[x]][S[x-1]]);
			bt.add(x+1,-E[S[x]][S[x+1]]);
			S[x]=y-1;
			if(x) bt.add(x,E[S[x]][S[x-1]]);
			bt.add(x+1,E[S[x]][S[x+1]]);
		}
		else {
			cout<<bt(y)-bt(x)<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

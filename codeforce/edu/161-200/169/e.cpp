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
int N,A[303030];

int G[10202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	G[1]=1;
	int nex=2;
	for(i=3;i<=10000000;i+=2) if(G[i]==0) {
		G[i]=nex;
		for(ll j=1LL*i*i;j<=10000000;j+=i) if(j%2&&G[j]==0) G[j]=nex;
		nex++;
	}
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		int ni=0;
		FOR(i,N) {
			cin>>A[i];
			ni^=G[A[i]];
		}
		if(ni) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

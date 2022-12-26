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


int N,M;
set<int> E[202020];
set<int> B[202020];

int isB[202020];
int C[202020],T[202020],D[202020];
int Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	FOR(i,N) if(E[i].size()>200) isB[i]=1;
	FOR(i,N) {
		FORR(e,E[i]) if(isB[e]) B[i].insert(e);
	}
	
	cin>>Q;
	for(i=1;i<=Q;i++) {
		cin>>x>>y;
		x--,y--;
		if(isB[x]) {
			cout<<(D[x]+1)<<endl;
			D[x]=C[x]=y;
			T[x]=i;
		}
		else {
			int t=T[x],c=C[x];
			FORR(e,E[x]) if(T[e]>t) t=T[e],c=C[e];
			cout<<c+1<<endl;
			C[x]=y;
			T[x]=i;
		}
		FORR(b,B[x]) D[b]=y;
	}
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

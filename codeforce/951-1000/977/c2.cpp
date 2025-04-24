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

int T,N,M,Q;
int B[202020],P[202020];
set<int> C[202020];

int hoge(int v) {
	if(v<0||v+1>=N) return 0;
	if(C[v].empty()) return 0;
	if(C[v+1].empty()) return 0;
	return *C[v].begin()>*C[v+1].begin();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>Q;
		FOR(i,N) {
			cin>>x;
			P[x]=i;
		}
		FOR(i,N+2) {
			C[i]={N+M+1};
		}
		FOR(i,M) {
			cin>>B[i];
			B[i]=P[B[i]];
			C[B[i]].insert(i);
		}
		
		int ng=0;
		FOR(i,N) ng+=hoge(i);
		if(ng) cout<<"TIDAK"<<endl;
		else cout<<"YA"<<endl;
		
		while(Q--) {
			cin>>x>>y;
			x--;
			y=P[y];
			
			k=B[x];
			
			int a=min(k,y),b=max(k,y);
			
			ng-=hoge(a-1);
			ng-=hoge(a);
			if(b-1>a) ng-=hoge(b-1);
			if(b>a) ng-=hoge(b);
			
			C[B[x]].erase(x);
			B[x]=y;
			C[B[x]].insert(x);
			k=B[x];
			ng+=hoge(a-1);
			ng+=hoge(a);
			if(b-1>a) ng+=hoge(b-1);
			if(b>a) ng+=hoge(b);
			
			if(ng) cout<<"TIDAK"<<endl;
			else cout<<"YA"<<endl;
		}
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

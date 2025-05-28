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
vector<pair<ll,ll>> ret;

int ask(int x1,int x2,int y1,int y2) {
	if(x2<x1||y2<y1) return 0;
	cout<<"? "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
	cin>>x1;
	return x1;
}

void dfs(int L,int R,int D,int U) {
	if(L>R) return;
	if(D>U) return;
	
	if(L==R&&U==D) {
		ret.push_back({L,D});
		return;
	}
	
	if(R-L>=U-D) {
		int M=(L+R)/2;
		if(ask(L,M,D,U)) dfs(L,M,D,U);
		if(ask(M+1,R,D,U)) dfs(M+1,R,D,U);
	}
	else {
		int M=(D+U)/2;
		if(ask(L,R,D,M)) dfs(L,R,D,M);
		if(ask(L,R,M+1,U)) dfs(L,R,M+1,U);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dfs(0,1000000,0,1000000);
	cout<<"! "<<ret.size()<<endl;
	FORR2(x,y,ret) cout<<x<<" "<<y<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

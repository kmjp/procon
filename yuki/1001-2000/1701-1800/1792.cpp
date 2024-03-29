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
int A[1010][6];
ll ret;
vector<int> V[4];

void dfs(int cur) {
	int i;
	if(cur<6) {
		
		FOR(i,4) {
			V[i].push_back(cur);
			dfs(cur+1);
			V[i].pop_back();
		}
		return;
	}
	FOR(i,4) if(V[i].empty()) return;
	ll C[4]={};
	int j;
	FOR(i,N) {
		ll D[4]={1,1,1,1};
		FOR(j,4) FORR(v,V[j]) D[j]*=A[i][v];
		FOR(j,4) C[j]=max(C[j],D[j]);
	}
	ret=max(ret,C[0]*C[1]*C[2]*C[3]);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(j,6) cin>>A[i][j];
	}
	
	V[0].push_back(0);
	dfs(1);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

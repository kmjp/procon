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
int V[1<<20];

void dfs(int cur,int d) {
	if(d==0) {
		return;
	}
	int x=1<<(d-1),i;
	FOR(i,x) {
		int a=V[cur+i];
		int b=V[cur+i+x];
		V[cur+i]=a&b;
		V[cur+x+i]=a&(b>>1);
	}
	dfs(cur,d-1);
	dfs(cur+x,d-1);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V[0]=1;
	for(i=1;i<=(1<<N)-1;i++) cin>>V[i];
	
	dfs(0,N);
	
	int num=0;
	FOR(i,1<<N) if(V[i]&1) num++;
	cout<<num<<"\n";
	FOR(i,1<<N) if(V[i]&1) cout<<i<<"\n";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int A[505050];
set<pair<int,int>> S[505050];
int num;
int N,Q;

void dfs(int t,int cur) {
	if(t>=A[cur]) return;
	if(A[cur]==1<<20) num++;
	A[cur]=t;
	while(S[cur].size()&&S[cur].rbegin()->first>t) {
		auto p=*S[cur].rbegin();
		S[cur].erase(p);
		dfs(p.first,p.second);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) A[i]=1<<20;
	num=1;
	A[0]=0;
	
	FOR(i,Q) {
		cin>>r>>x>>y;
		x--,y--;
		if(A[x]>A[y]) swap(x,y);
		if(r<A[x]&&r<A[y]) {
			S[x].insert({r,y});
			S[y].insert({r,x});
		}
		if(A[x]<r) dfs(r,y);
		cout<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

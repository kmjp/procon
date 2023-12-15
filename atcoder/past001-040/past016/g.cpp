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
int A[12];
vector<int> V[4];

int ret;
int ok(int a,int b,int c) {
	return (A[a]+A[b]>A[c]);
}

void dfs(int cur) {
	int i;
	if(cur==3*N) {
		FOR(i,N) if(A[V[i][0]]+A[V[i][1]]<=A[V[i][2]]) return;
		ret++;
		return;
	}
	FOR(i,N) {
		if(V[i].size()<3) {
			V[i].push_back(cur);
			dfs(cur+1);
			V[i].pop_back();
			if(V[i].empty()) return;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3*N) {
		cin>>A[i];
	}
	sort(A,A+3*N);
	dfs(0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

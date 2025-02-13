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

vector<vector<int>> A[2];
map<vector<vector<int>>,int> B[2];

map<vector<vector<int>>,int> hoge(vector<vector<int>> A) {
	queue<vector<vector<int>>> Q;
	map<vector<vector<int>>,int> M;
	M[A]=0;
	Q.push(A);
	while(Q.size()) {
		vector<vector<int>> C=Q.front();
		Q.pop();
		if(M[C]>=15) break;
		int co=M[C]+1;
		int ty,tx,y,x;
		FOR(y,4) FOR(x,4) if(C[y][x]==-1) ty=y,tx=x;
		if(ty>0) {
			swap(C[ty][tx],C[ty-1][tx]);
			if(M.count(C)==0) M[C]=co, Q.push(C);
			swap(C[ty][tx],C[ty-1][tx]);
		}
		if(ty<3) {
			swap(C[ty][tx],C[ty+1][tx]);
			if(M.count(C)==0) M[C]=co, Q.push(C);
			swap(C[ty][tx],C[ty+1][tx]);
		}
		if(tx>0) {
			swap(C[ty][tx],C[ty][tx-1]);
			if(M.count(C)==0) M[C]=co, Q.push(C);
			swap(C[ty][tx],C[ty][tx-1]);
		}
		if(tx<3) {
			swap(C[ty][tx],C[ty][tx+1]);
			if(M.count(C)==0) M[C]=co, Q.push(C);
			swap(C[ty][tx],C[ty][tx+1]);
		}
	}
		
	
	return M;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		A[i].resize(4);
		FOR(y,4) {
			A[i][y].resize(4);
			FOR(x,4) cin>>A[i][y][x];
		}
		B[i]=hoge(A[i]);
	}
	int ret=31;
	FORR2(a,b,B[0]) if(B[1].count(a)) ret=min(ret,b+B[1][a]);
	if(ret>30) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

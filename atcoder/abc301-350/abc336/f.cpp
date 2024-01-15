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

int H,W;
int A[64],B[64];


vector<vector<int>> hoge(vector<int> A) {
	int C[8][8];
	int y,x,ay,ax;
	vector<vector<int>> V;
	FOR(ax,2) FOR(ay,2) {
		FOR(y,H) FOR(x,W) {
			C[y][x]=A[y*W+x];
		}
		FOR(y,H-1) FOR(x,W-1) {
			int ty=H-2-y,tx=W-2-x;
			if(y*W+x<ty*W+tx) swap(C[y+ay][x+ax],C[ty+ay][tx+ax]);
		}
		vector<int> X;
		FOR(y,H) FOR(x,W) X.push_back(C[y][x]);
		V.push_back(X);
	}
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<int> A,B;
	FOR(y,H) {
		FOR(x,W) {
			cin>>i;
			A.push_back(i-1);
			B.push_back(y*W+x);
		}
	}
	map<vector<int>,int> M[2];
	queue<pair<int,vector<int>>> Q;
	M[0][A]=0;
	M[1][B]=0;
	Q.push({0,A});
	Q.push({1,B});
	while(Q.size()) {
		int id=Q.front().first;
		auto V=Q.front().second;
		Q.pop();
		if(M[id][V]>=10) continue;
		auto Vs=hoge(V);
		FORR(v,Vs) if(M[id].count(v)==0) {
			M[id][v]=M[id][V]+1;
			Q.push({id,v});
		}
	}
	
	int ret=100;
	
	FORR2(a,b,M[0]) if(M[1].count(a)) ret=min(ret,b+M[1][a]);
	if(ret>30) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

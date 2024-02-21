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

int H,W,K;
string S[101][101];
int num[101];
int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K+1) {
		FOR(y,H) {
			cin>>S[i][y];
		}
	}
	
	FOR(i,K+1) FOR(j,K+1) {
		FOR(y,H) FOR(x,W) if(S[i][y][x]!=S[j][y][x]) {
			if(S[i][y][x]!=S[i][y-1][x]) D[i][j]=1;
		}
	}
	vector<int> V;
	FOR(i,K+1) V.push_back(i);
	FOR(i,K) FOR(j,K) if(D[V[j+1]][V[j]]) swap(V[j],V[j+1]);
	cout<<V[0]+1<<endl;
	vector<vector<int>> R;
	FOR(i,K) {
		int a=V[i];
		int b=V[i+1];
		FOR(y,H) FOR(x,W) if(S[a][y][x]!=S[b][y][x]) R.push_back({1,y+1,x+1});
		R.push_back({2,b+1});
	}
	cout<<R.size()<<endl;
	FORR(r,R) {
		FORR(a,r) cout<<a<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

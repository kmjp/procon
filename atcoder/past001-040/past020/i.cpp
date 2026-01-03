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

vector<int> V;
map<vector<int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,8) V.push_back(i+1);
	M[V]=0;
	queue<vector<int>> Q;
	Q.push(V);
	while(Q.size()) {
		V=Q.front();
		Q.pop();
		int cur=M[V];
		FOR(y,2) FOR(x,3) {
			swap(V[y*4+x],V[y*4+x+1]);
			if(M.count(V)==0) M[V]=cur+1, Q.push(V);
			swap(V[y*4+x],V[y*4+x+1]);
		}
		FOR(y,1) FOR(x,4) {
			swap(V[y*4+x],V[y*4+x+4]);
			if(M.count(V)==0) M[V]=cur+1, Q.push(V);
			swap(V[y*4+x],V[y*4+x+4]);
		}
	}
	FOR(i,8) cin>>V[i];
	cout<<M[V]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

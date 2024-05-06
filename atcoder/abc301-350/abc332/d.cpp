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
ll A[5][5],B[5][5];

int cost(vector<int> V) {
	int ret=0,x,y;
	FOR(y,V.size()) FOR(x,y) if(V[x]>V[y]) ret++;
	return ret++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) FOR(x,W) cin>>B[y][x];
	vector<int> Hs,Ws;
	FOR(y,H) Hs.push_back(y);
	FOR(x,W) Ws.push_back(x);
	int mi=1<<20;
	do {
		do {
			int ok=1;
			FOR(y,H) FOR(x,W) if(A[Hs[y]][Ws[x]]!=B[y][x]) ok=0;
			if(ok) mi=min(mi,cost(Ws)+cost(Hs));
		} while(next_permutation(ALL(Ws)));
		
	} while(next_permutation(ALL(Hs)));
	
	if(mi==1<<20) {
		mi=-1;
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

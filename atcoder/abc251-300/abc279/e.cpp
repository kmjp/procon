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

int N,M;

set<int> V[202020];
int R[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) V[0].insert(i);
	
	FOR(i,M) {
		cin>>x;
		x--;
		int a=-1,b=-1;
		if(V[x].count(i)) {
			a=x;
			V[x].erase(i);
		}
		if(V[x+1].count(i)) {
			a=x+1;
			V[x+1].erase(i);
		}
		swap(V[x],V[x+1]);
		if(a!=-1) V[a].insert(i);
	}
	FOR(i,N) FORR(e,V[i]) R[e]=i+1;
	
	FOR(i,M) cout<<R[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

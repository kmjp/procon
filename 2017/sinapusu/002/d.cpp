#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<pair<int,int>> V;
vector<pair<int,int>> R[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) cin>>x, V.push_back({x,i});
	
	FOR(i,N) {
		vector<pair<int,int>> V2;
		FOR(j,V.size()/2) {
			V2.push_back(max(V[j*2],V[j*2+1]));
			R[i].push_back(min(V[j*2],V[j*2+1]));
		}
		V=V2;
	}
	for(i=N-1;i>=0;i--) {
		FOR(j,R[i].size()) _P("%d%c",R[i][j].second,(j==R[i].size()-1)?'\n':' ');
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

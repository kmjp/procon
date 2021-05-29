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
map<int,int> M[2];
vector<pair<int,int>> V[2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M[i%2][x]++;
	}
	FOR(i,2) {
		V[i].push_back({0,-1-i});
		V[i].push_back({0,-3-i});
		FORR(m,M[i]) V[i].push_back({m.second,m.first});
		sort(ALL(V[i]));
		reverse(ALL(V[i]));
		V[i].resize(2);
	}
	
	int ret=1<<30;
	FOR(x,2) FOR(y,2) if(V[0][x].second !=V[1][y].second) ret=min(ret,N-V[0][x].first-V[1][y].first);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

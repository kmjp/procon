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


int N,M;
vector<pair<int,char>> add[202020];
vector<pair<int,char>> del[202020];

int cnt[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>s;
		add[x].push_back({i,s[0]});
		del[y+1].push_back({i,s[0]});
	}
	
	set<pair<int,int>> S;
	S.insert({505050,'a'});
	for(i=1;i<=N;i++) {
		FORR(a,add[i]) S.insert(a);
		FORR(a,del[i]) S.erase(a);
		cnt[S.begin()->second]++;
	}
	cout<<cnt['Y']<<" "<<cnt['K']<<" "<<cnt['C']<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

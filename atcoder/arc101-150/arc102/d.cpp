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


int L;
vector<pair<int,int>> E[21];

vector<int> cand[21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L;
	L--;
	
	for(i=2;i<=19;i++) {
		E[i].push_back({i+1,0});
		E[i].push_back({i+1,1<<(19-i)});
	}
	
	FOR(i,18) if(L&(1<<i)) if(i!=19) E[1].push_back({20-i,L&~((2<<i)-1) });
	FOR(i,L>>18) E[1].push_back({2,i<<18});
	
	E[1].push_back({20,L});
	
	int N=20,M=0;
	FOR(i,20) M+=E[i].size();
	cout<<N<<" "<<M<<endl;
	FOR(i,20) FORR(e,E[i]) cout<<i<<" "<<e.first<<" "<<e.second<<endl;
	
	cand[1].push_back(0);
	for(i=1;i<20;i++) {
		FORR(c,cand[i]) FORR(e,E[i]) cand[e.first].push_back(c+e.second);
	}
	
	sort(ALL(cand[20]));
	assert(cand[20].size()==L+1);
	cand[20].erase(unique(ALL(cand[20])),cand[20].end());
	assert(cand[20].size()==L+1);
	assert(cand[20][0]==0);
	assert(cand[20].back()==L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

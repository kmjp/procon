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
set<int> S[2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(S[x%2].count(x)) S[x%2].erase(x);
		else S[x%2].insert(x);
	}
	
	if(S[1].size()%2) return _P("-1\n");
	vector<pair<int,int>> V;
	
	vector<int> VV;
	FORR(e,S[1]) VV.push_back(e);
	for(i=0;i<VV.size();i+=2) {
		V.push_back({VV[i+1],VV[i]});
		V.push_back({(VV[i+1]-VV[i]),(VV[i+1]-VV[i])/2});
	}
	
	FORR(e,S[0]) V.push_back({e,e/2});
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

string A,B;
vector<pair<char,int>> RLE(string S) {
	vector<pair<char,int>> R;
	FORR(c,S) {
		if(R.empty()) R.push_back({c,1});
		else if(R.back().first == c) R.back().second++;
		else R.push_back({c,1});
	}
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	
	auto AA=RLE(A);
	auto BB=RLE(B);
	if(AA.size()!=BB.size()) return _P("0\n");
	FOR(i,AA.size()) {
		if(AA[i].first!=BB[i].first) return _P("0\n");
		if(AA[i].second>BB[i].second) return _P("0\n");
	}
	_P("1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

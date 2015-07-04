#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int L,K;
string S;

vector<pair<char,int> > RLE(string S) {
	vector<pair<char,int> > V;
	FORR(r,S) {
		if(V.size() && V.back().first==r) V.back().second++;
		else V.push_back({r,1});
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	L=S.size();
	auto V=RLE(S);
	
	FOR(i,V.size()) {
		if(V[i].first=='s' && (i==V.size()-1 || V[i+1].first<'s')) {
			x=min(K,V[i].second);
			V[i].second -= x;
			K -= x;
		}
	}
	for(i=V.size()-1;i>=0;i--) if(V[i].first=='s') {
		x=min(K,V[i].second);
		V[i].second -= x;
		K -= x;
	}
	
	FORR(r,V) FOR(i,r.second) _P("%c",r.first);
	_P("\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

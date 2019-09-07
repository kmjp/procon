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
ll S[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) cin>>S[i];
	sort(S,S+(1<<N));
	multiset<int> T;
	FOR(i,(1<<N)-1) T.insert(S[i]);
	
	vector<int> V;
	V.push_back(S[(1<<N)-1]);
	FOR(i,N) {
		vector<int> W=V;
		
		FORR(v,V) {
			auto it=T.lower_bound(v);
			if(it==T.begin()) return _P("No\n");
			it--;
			W.push_back(*it);
			T.erase(it);
		}
		
		sort(ALL(W));
		reverse(ALL(W));
		swap(V,W);
	}
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

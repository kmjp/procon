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
ll A[202020],B[202020];
ll C[202020],D[202020];
vector<pair<int,int>> E;

int ma;
map<int,int> FF;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i]>>B[i], E.push_back({A[i],i+200000});
	FOR(i,M) cin>>C[i]>>D[i], E.push_back({D[i],i});
	
	sort(ALL(E));
	FORR(r,E) {
		x=r.second;
		if(x>=200000) {
			x-=200000;
			auto k=FF.lower_bound(B[x]);
			if(k!=FF.end()) {
				ma++;
				if(--k->second==0) FF.erase(k);
			}
		}
		else {
			FF[C[x]]++;
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

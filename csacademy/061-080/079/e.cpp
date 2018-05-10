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

int N,K;
vector<ll> V;
multiset<ll> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	V.resize(N);
	ll dif=0;
	FOR(i,N) {
		cin>>V[i];
		if(V[i]<0) {
			dif+=V[i];
			V[i]=-V[i];
		}
	}
	sort(ALL(V));
	
	multiset<pair<ll,int>> M;
	R.insert(0);
	M.insert({0,0});
	while(M.size()) {
		auto a=*M.begin();
		M.erase(M.begin());
		
		if(R.size()>=K && *R.rbegin()<=a.first) break;
		if(a.second<N) {
			R.insert(a.first+V[a.second]);
			if(R.size()>K) R.erase(--R.end());
			if(R.size()<K || a.first+V[a.second]<*R.rbegin()) {
				M.insert({a.first+V[a.second],a.second+1});
				M.insert({a.first,a.second+1});
			}
		}
		
	}
	
	FORR(r,R) cout<<dif+r<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

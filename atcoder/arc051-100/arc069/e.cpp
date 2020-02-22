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
ll A[101010];
vector<int> V;
ll ret[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<ll,ll> M;
	FOR(i,N) cin>>A[i], M[A[i]]++;
	V.push_back(0);
	for(i=1;i<N;i++) if(A[V.back()]<A[i]) V.push_back(i);
	for(i=V.size()-2;i>=0;i--) {
		while(M.rbegin()->first>A[V[i]]) {
			auto r=*M.rbegin();
			M.erase(r.first);
			ret[V[i+1]] += (r.first-A[V[i]])*1LL*r.second;
			M[A[V[i]]]+=r.second;
		}
	}
	FORR(r,M) ret[0] += r.first*r.second;
	
	
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

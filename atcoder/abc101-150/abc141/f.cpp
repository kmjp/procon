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
ll X;

template<class C> vector<C> gf2_rank(vector<C>& V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		int x=max_element(V.begin()+i,V.end())-V.begin();
		if(V[x]==0) break;
		swap(V[i],V[x]);
		C msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		FOR(j,N) if(j!=i) if(V[j]&msb) V[j]^=V[i];
	}
	while(V.size() && V.back()==0) V.pop_back();
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> V;
	FOR(i,N) {
		cin>>A[i];
		X^=A[i];
	}
	FOR(i,N) {
		A[i]&=~X;
		V.push_back(A[i]);
	}
	auto W=gf2_rank(V);
	ll ret=0;
	FORR(v,V) ret=max(ret,ret^v);
	cout<<ret*2+X<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

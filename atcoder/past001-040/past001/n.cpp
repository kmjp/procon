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

int N,W,C;
int L[101010],R[101010],P[101010];
ll A[202020],B[202020];
vector<ll> Xs;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>C;
	Xs.push_back(-1);
	Xs.push_back(0);
	Xs.push_back(W);
	Xs.push_back(W+1);
	FOR(i,N) {
		cin>>L[i]>>R[i]>>P[i];
		Xs.push_back(L[i]);
		Xs.push_back(R[i]);
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,N) {
		L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
		R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
		A[L[i]]+=P[i];
		A[R[i]]-=P[i];
		B[L[i]]+=P[i];
	}
	for(i=1;i<Xs.size();i++) {
		A[i]+=A[i-1];
		B[i]+=B[i-1];
	}
	ll mi=1LL<<60;
	for(x=1;x<Xs.size();x++) {
		if(Xs[x]+C>W) break;
		y=lower_bound(ALL(Xs),Xs[x]+C)-Xs.begin();
		mi=min(mi,A[x]+B[y-1]-B[x]);
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

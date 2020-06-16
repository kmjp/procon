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

int N,Q;
int A[202020],B[202020];
multiset<int> K[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		K[B[i]].insert(-A[i]);
	}
	
	multiset<int> cand;
	for(i=1;i<=200000;i++) {
		if(K[i].size()) cand.insert(-*K[i].begin());
	}
	
	while(Q--) {
		int C,D;
		cin>>C>>D;
		C--;
		cand.erase(cand.find(-*K[B[C]].begin()));
		K[B[C]].erase(K[B[C]].find(-A[C]));
		if(K[B[C]].size()) cand.insert(-*K[B[C]].begin());
		B[C]=D;
		if(K[D].size()) cand.erase(cand.find(-*K[D].begin()));
		K[D].insert(-A[C]);
		cand.insert(-*K[D].begin());
		cout<<*cand.begin()<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

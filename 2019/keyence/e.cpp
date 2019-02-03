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
ll D;
ll A[202020];
ll L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		ret+=A[i];
		
		L[i]=max((i?L[i-1]:-1LL<<60),i*D-A[i]);
	}
	ret+=(N-1)*D;
	
	for(i=N-1;i>=0;i--) {
		R[i]=min((i<N-1?R[i+1]:1LL<<60),i*D+A[i]);
		if(i>0 && i<N-1) ret+=min(i*D-L[i],R[i]-(i*D));
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

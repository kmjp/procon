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

int N,M,K;
int L[3030],R[3030];
ll mo=1000000007;
ll from[3030];
ll to[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) cin>>L[i]>>R[i];
	
	from[1]=1;
	FOR(i,K) {
		ZERO(to);
		FOR(x,N+1) if(x) (from[x]+=from[x-1])%=mo;
		
		FOR(x,M) {
			ll sum=(from[R[x]]-from[L[x]-1]+mo)%mo;
			(to[L[x]]+=sum)%=mo;
			(to[R[x]+1]+=mo-sum)%=mo;
		}
		
		FOR(x,N+1) (to[x+1]+=to[x])%=mo;
		swap(from,to);
	}
	
	cout<<from[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

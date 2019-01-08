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
ll memo[404][404];
int A[404];
ll SA[404];

ll dpdp(int L,int R) {
	if(L+1==R) return 0;
	if(memo[L][R]>=0) return memo[L][R];
	memo[L][R]=1LL<<60;
	for(int M=L+1;M<R;M++) memo[L][R]=min(memo[L][R],dpdp(L,M)+dpdp(M,R));
	return memo[L][R]+=SA[R-1]-SA[L-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		SA[i]=SA[i-1]+A[i];
	}
	
	cout<<dpdp(1,N+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

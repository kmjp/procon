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
ll A[3010101];
ll SA[3010101];
ll P[3010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>x, A[x]++;
	
	ll ret=0;
	for(i=1000000;i>=1;i--) {
		ll tot=0;
		for(j=i;j<=3000000;j+=i) {
			SA[j]=SA[j-i]+A[j];
			tot=SA[j];
			P[i]-=P[j];
		}
		for(j=i;j<=1000000;j+=i) {
			int sum=(K-j+i-1)/i*i;
			if(sum<=j) sum=j+i;
			P[i]+=A[j]*(tot-SA[sum-i]);
		}
		
		if(K%i==0) ret+=P[i];
	}
	
	ret+=A[K]*(A[K]-1)/2;
	if(K%2==0) ret+=A[K/2]*(A[K/2]-1)/2;
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

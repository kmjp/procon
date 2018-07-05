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
ll M,A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	A[N]=1LL<<61;
	
	ll ret=(1LL<<60);
	for(i=60;i>=0;i--) {
		ret -= 1LL<<i;
		x = lower_bound(A,A+N,ret)-A;
		if(A[x]==ret) x++;
		ll val = ret-x;
		if(val<M) ret+=1LL<<i;
		
	}
	ll sum=ret*(ret+1)/2;
	FOR(i,N) if(A[i]<=ret) sum-=A[i];
	
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

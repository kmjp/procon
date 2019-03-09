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
ll K;
ll A[101010];
ll num[42];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		FOR(j,41) if(A[i]&(1LL<<j)) num[j]++;
	}
	
	ll ma=-1;
	ll ret=0;
	FOR(i,41) ret+=num[i]<<i;
	ma=ret;
	
	ret=0;
	FOR(j,41) {
		if((K>>j)&1) ret+=(N-num[j])<<j;
		else ret+=num[j]<<j;
	}
	ma=max(ma,ret);
	
	FOR(i,41) if(K&(1LL<<i)) {
		ll ret=0;
		FOR(j,41) {
			if(j>i) {
				if((K>>j)&1) ret+=(N-num[j])<<j;
				else ret+=num[j]<<j;
			}
			if(j==i) ret+=num[j]<<j;
			if(j<i) ret+=max(N-num[j],num[j])<<j;
		}
		ma=max(ma,ret);
	}
	
	
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
unsigned long long B[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ret=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(x==1<<26) {
			ret |= 1<<26;
			x ^= 1<<26;
		}
		x ^= (1<<26)-1;
		B[x>>6] |= 1ULL<<(x&63);
	}
	FOR(i,26) {
		if(i<6) {
			unsigned long long mask[6]={
				0xAAAAAAAAAAAAAAAAULL,
				0xCCCCCCCCCCCCCCCCULL,
				0xF0F0F0F0F0F0F0F0ULL,
				0xFF00FF00FF00FF00ULL,
				0xFFFF0000FFFF0000ULL,
				0xFFFFFFFF00000000ULL,
			};
			FOR(j,1<<20) B[j] |= (B[j]&mask[i])>>(1<<i);
		}
		else {
			FOR(j,1<<20) if((j&(1<<(i-6)))==0) B[j] |= B[j | (1<<(i-6))];
		}
	}
	
	int mi=(1<<26)-1;
	for(i=(1<<26)-1;i>=1;i--) if((B[i>>6]&(1LL<<(i&63)))==0 && __builtin_popcount(i)<=__builtin_popcount(mi)) mi=i;
	cout<<ret+mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

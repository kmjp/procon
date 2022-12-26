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

int N,M;
int A[101010],B[101010],C[101010];
ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

map<pair<int,int>,int> mp;

ll dp[101010][1<<4];

int out(int x,int y,int val) {
	if(mp.count({x,y})==0) return 0;
	if(mp[{x,y}]==(val&1)) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		mp[{A[i],B[i]}]=C[i];
		if(abs(A[i]-B[i])>2) {
			if(mp.count({B[i],A[i]}) && mp[{B[i],A[i]}]!=C[i]) return _P("0\n");
			mp[{B[i],A[i]}]=C[i];
		}
	}
	
	ll fr=0;
	FOR(i,N) fr+=N-(min(N-1,i+2)-max(i-2,0)+1);
	FORR(m,mp) if(abs(m.first.first-m.first.second)>2) fr--;
	fr/=2;
	ll pat=modpow(2,fr);
	
	int mask;
	FOR(mask,1<<4) if(__builtin_popcount(mask)%2==0) {
		int ng=0;
		FOR(y,2) FOR(x,2) ng|=out(x,y,(mask>>(y*2+x))%2);
		if(ng==0) dp[1][mask]++;
	}
	
	for(i=2;i<N;i++) {
		FOR(mask,1<<5) if(__builtin_popcount(mask)%2==0) {
			if(out(i,i,mask>>4)) continue;
			if(out(i-1,i,mask>>3)) continue;
			if(out(i-2,i,mask>>2)) continue;
			if(out(i,i-1,mask>>1)) continue;
			if(out(i,i-2,mask>>0)) continue;
			int mask2;
			FOR(mask2,1<<4) if(__builtin_popcount(mask2)%2==0) {
				int nmask=(mask2>>3)&1;
				nmask |= ((mask>>1)&1)<<1;
				nmask |= ((mask>>3)&1)<<2;
				nmask |= ((mask>>4)&1)<<3;
				if(__builtin_popcount(nmask)%2==0) (dp[i][nmask]+=dp[i-1][mask2])%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(i,1<<4) ret+=dp[N-1][i];
	cout<<ret%mo*pat%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

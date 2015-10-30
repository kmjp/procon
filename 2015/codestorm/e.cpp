#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,M;
int grundy[1010100];
int tg[4][1010100];
ll mo=1000000007;
ll po[1010100];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	po[0]=1;
	for(i=1;i<=1000000;i++) {
		po[i]=modpow(2,i);
		j=1;
		set<int> mex;
		while(j*10<=i) {
			x = (i%j) + (i/j+i/(10*j))%10*j+i/(100*j)*(10*j);
			mex.insert(grundy[x]);
			j*=10;
		}
		while(mex.count(grundy[i])) grundy[i]++;
		
		FOR(j,4) tg[j][i]=tg[j][i-1] + (grundy[i]==j);
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		int num[4];
		FOR(j,4) num[j]=tg[j][N];
		int nim=0;
		FOR(i,M) cin>>x, num[grundy[x]]--, nim ^= grundy[x];
		
		ll ret=0;
		FOR(i,2) FOR(j,2) FOR(k,2) if((nim ^ i ^ (j*2) ^ (k*3)) == 0) {
			ll v = 1;
			if(i && num[1]==0) continue;
			if(j && num[2]==0) continue;
			if(k && num[3]==0) continue;
			if(num[1]) (v *= po[num[1]-1])%=mo;
			if(num[2]) (v *= po[num[2]-1])%=mo;
			if(num[3]) (v *= po[num[3]-1])%=mo;
			ret += v;
		}
		ret %= mo;
		(ret *= po[num[0]])%=mo;
		if(nim==0) ret+=mo-1;
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

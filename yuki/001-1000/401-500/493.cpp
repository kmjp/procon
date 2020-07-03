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

int K;
ll L,R;
ll F[100],S[100],P[100];
ll mo=1000000007;

string ST[100];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

pair<ll,ll> getval(int K,ll V) {
	if(V<=0) return {0,1};
	
	if(V==F[K]) return {S[K],P[K]};
	if(V<=F[K-1]) return getval(K-1,V);
	
	ll sum=S[K-1],prod=P[K-1];
	V -= F[K-1];
	
	ll i;
	FOR(i,min(V,(ll)ST[K].size())) {
		sum += ST[K][i];
		(prod *= ST[K][i])%=mo;
	}
	
	auto r=getval(K-1,V-ST[K].size());
	sum += r.first;
	(prod *= r.second)%=mo;
	return {sum,prod};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[1]=S[1]=P[1]=1;
	ST[1]="1";
	ST[1][0]-='0';
	for(i=2;i<=61;i++) {
		F[i]=2*F[i-1];
		S[i]=2*S[i-1];
		P[i]=P[i-1]*P[i-1]%mo;
		
		char buf[20];
		sprintf(buf,"%d",i*i);
		ST[i]=buf;
		FORR(c,ST[i]) {
			c-='0';
			if(c==0) c+=10;
			F[i]++;
			S[i]+=c;
			P[i]=P[i]*c%mo;
		}
	}
	
	cin>>K>>L>>R;
	K=min(K,60);
	if(R>F[K]) return _P("-1\n");
	
	auto RR = getval(60,R);
	auto LL = getval(60,L-1);
	cout<<RR.first-LL.first<<" "<<RR.second*modpow(LL.second)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

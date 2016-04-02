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

ll A,B,mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll gogo(ll d,ll step) {
	if(d<=1) return d;
	
	ll v=gogo(d/2,step);
	v = ((v*modpow(step,d/2)%mo)+v)%mo;
	if(d%2==0) return v;
	else return (v*step+1)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>mo;
	ll G=__gcd(A,B);
	
	ll X=gogo(G,10);
	ll Y=gogo(A/G,modpow(10,G));
	ll Z=gogo(B/G,modpow(10,G));
	cout<<X*Y%mo*Z%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

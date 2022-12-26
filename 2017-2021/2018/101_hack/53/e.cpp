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

int T,Q,type;
ll H,W,Y,X,R,D;
ll Y1,Y2,X1,X2;
ll mo;
vector<ll> P[2];
ll phi[2];

vector<ll> enumpr(ll n) {
	vector<ll> V;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) {
			V.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) V.push_back(n);
	sort(V.begin(),V.end());
	return V;
}

ll modpow(ll a, ll n,ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

__int128 hoge1(__int128 YY,__int128 XX) {
	if(YY<=0 || XX<=0) return 0;
	__int128 ret=YY*XX;
	(ret+=YY*R%mo*((XX*(XX-1)/2)%mo));
	(ret+=XX*D%mo*((YY*(YY-1)/2)%mo));
	return ret%mo;
}

ll hoge(ll v,vector<ll> p) {
	ll ret=0;
	int i;
	for(int mask=0;mask<1<<p.size();mask++) {
		int s=1;
		ll t=1;
		FOR(i,p.size()) if(mask&(1<<i)) s=-s, t*=p[i];
		ret+=s*(v/t);
	}
	return ret;
}

int totient(int v) {
	int ret=v;
	for(int i=2;i*i<=v;i++) if(v%i==0) {
		ret=ret/i*(i-1);
		while(v%i==0) v/=i;
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>Y>>X>>Q;
		mo=H*W;
		
		Y--;
		X--;
		
		P[0]=enumpr(H);
		P[1]=enumpr(W);
		
		if(W>=2) {
			R=H*modpow(H,totient(W)-1,W);
		}
		else {
			R=H;
		}
		if(H>=2) {
			D=W*modpow(W,totient(H)-1,H);
		}
		else {
			D=W;
		}
		
		
		while(Q--) {
			cin>>type>>Y1>>X1>>Y2>>X2;
			Y1--,X1--,Y2--,X2--;
			X1-=X;
			X2-=X;
			Y1-=Y;
			Y2-=Y;
			if(X1<0) X1+=W, X2+=W;
			if(Y1<0) Y1+=H, Y2+=H;
			
			ll ret=0;
			if(type==1) {
				ret=hoge1(Y2+1,X2+1)-hoge1(Y1,X2+1)-hoge1(Y2+1,X1)+hoge1(Y1,X1);
				cout<<(ret+4*mo)%mo<<endl;
			}
			else {
				ll y1=hoge(Y1,P[0]);
				ll y2=hoge(Y2+1,P[0]);
				ll x1=hoge(X1,P[1]);
				ll x2=hoge(X2+1,P[1]);
				ret=y2*x2-y2*x1-y1*x2+y1*x1;
				cout<<ret<<endl;
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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


int T;
ll A,X,B,Y,C,TC;

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll totient(ll v) {
	cprime();
	ll ret=v;
	FORR(p,prime) {
		if(1LL*p*p>v) break;
		if(v%p==0) {
			ret=ret/p*(p-1);
			while(v%p==0) v/=p;
		}
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}

ll modpow(ll a, ll n,ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>X>>B>>Y>>C;
		ll g=__gcd(A,B),g2;
		
		A/=g;	B/=g;	C/=__gcd(g,C);
		g=__gcd(A,C);	A/=g;	C/=g;	g2=gcd(B,g);	B/=g2;	Y/=g/g2;
		g=__gcd(B,C);	B/=g;	C/=g;	g2=gcd(A,g);	A/=g2;	X/=g/g2;
		if(C==1) {
			cout<<X+Y<<endl;
			continue;
		}
		A%=C;
		B%=C;
		
		TC=totient(C);
		
		vector<vector<ll>> cand;
		ll D=A*modpow(B,TC-1,C)%C;
		cand.push_back({0,C,0});
		ll H=D,W=0;
		while(1) {
			H%=(C-W);
			if(H==0) {
				H=C-W;
				break;
			}
			ll dif=(C-W)%H;
			if(dif==0) break;
			ll step=(C-W)/H;
			W=C-dif;
			ll X=W*modpow(D,TC-1,C)%C;
			ll Y=(C-D*X%C)%C;
			cand.push_back({X,Y,step});
		}
		cand.push_back({C,0,(C-W)/H});
		
		ll ret=0;
		FORR(c,cand) {
			if(c[0]==0) ret=max(ret,Y/c[1]);
			else if(c[1]==0) ret=max(ret,X/c[0]);
			else ret=max(ret,min(X/c[0],Y/c[1]));
		}
		FOR(i,cand.size()-1) {
			ll AX=cand[i][0],AY=cand[i][1];
			ll BX=cand[i+1][0],BY=cand[i+1][1];
			if(AY*X<=AX*Y || BY*X>=BX*Y) continue;
			ll step=cand[i+1][2];
			ll g=__gcd(BX-AX,AY-BY);
			assert(g%step==0);
			ll dx=(BX-AX)/step;
			ll dy=(BY-AY)/step;
			
			int cur=0;
			for(j=29;j>=0;j--) if(cur+(1<<j)<step) {
				ll CX=AX+(cur+(1<<j))*dx;
				ll CY=AY+(cur+(1<<j))*dy;
				if(CY*X>CX*Y) cur+=1<<j;
			}
			ll TX=AX+cur*dx;
			ll TY=AY+cur*dy;
			ll SX=TX+dx;
			ll SY=TY+dy;
			ret=max(ret,min(TX?(X/TX):(1<<30),TY?(Y/TY):(1<<30)));
			ret=max(ret,min(SX?(X/SX):(1<<30),SY?(Y/SY):(1<<30)));
			FOR(r,2) {
				ll mx=0;
				for(j=29;j>=0;j--) {
					__int128_t lef=(-TX*(mx+(1<<j))+X)*(__int128_t)SY;
					__int128_t ri=(-TY*(mx+(1<<j))+Y)*(__int128_t)SX;
					if(lef<ri) mx+=1<<j;
				}
				for(ll x=max(0LL,mx-2);x<=mx+2;x++) if(x>=0) {
					ll LX=X-TX*x;
					ll LY=Y-TY*x;
					if(LX>=0&LY>=0) {
						ret=max(ret,x+min(SX?(LX/SX):(1<<30),SY?(LY/SY):(1<<30)));
						ll y=min(SX?(LX/SX):(1<<30),SY?(LY/SY):(1<<30));
						ll XX=TX*x+SX*y;
						ll YY=TY*x+SY*y;
					}
				}
				swap(TX,SY);
				swap(SX,TY);
				swap(X,Y);
			}
		}
		
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

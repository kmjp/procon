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

int N,Q;
ll A,B;
ll C[101010];
ll mo=1000000007;
ll V;
ll P[101010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>Q;
	
	V = (mo-B) * modpow(A) % mo;
	P[0]=1;
	
	FOR(i,N) {
		cin>>C[i];
		bt.add(i+1,C[i]*P[i]%mo);
		P[i+1]=P[i]*V%mo;
	}
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			bt.add(x+1,(mo-(C[x]*P[x]%mo))%mo);
			C[x]=y;
			bt.add(x+1,C[x]*P[x]%mo);
		}
		else {
			if(B==0) {
				if(C[x]%mo==0) {
					cout<<"Yes"<<endl;
				}
				else {
					cout<<"No"<<endl;
				}
			}
			else {
				ll v=bt(y+1)-bt(x);
				if(v%mo==0) {
					cout<<"Yes"<<endl;
				}
				else {
					cout<<"No"<<endl;
				}
			}
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

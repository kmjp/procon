#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
ll A,B,S,G,mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

map<int,int> M;
ll modlog(int g,int a) {  // return g^x=a mod mo
	M.clear();
	ll cur=1;
	int sq=sqrt(mo);
	int i;
	FOR(i,sq) {
		if(M.count(cur)==0) M[cur]=i;
		cur=cur*g%mo;
	}
	
	ll step=cur;
	cur=1;
	ll num=0;
	int lp=0;
	while(1) {
		ll x=a*modpow(cur)%mo;
		if(lp++>sq+5) return 1LL<<50;
		if(M.count(x)) return num+M[x];
		cur=cur*step%mo;
		num+=sq;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>mo>>A>>B>>S>>G;
		if(S==G) {
			cout<<0<<endl;
			continue;
		}
		if(A==0) {
			if(B==G) {
				cout<<1<<endl;
			}
			else {
				cout<<-1<<endl;
			}
			continue;
		}
		if(A==1) {
			if(B==0) {
				cout<<-1<<endl;
			}
			else {
				ll ret=(G-S+mo)*modpow(B)%mo;
				cout<<ret<<endl;
			}
			continue;
		}
		ll L=((A-1)*S+B)%mo;
		ll R=(G*(A-1)+B)%mo;
		if(L==0||R==0) {
			cout<<-1<<endl;
			continue;
		}
		R=R*modpow(L)%mo;
		
		ll ret=modlog(A,R);
		if(ret==1LL<<50) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

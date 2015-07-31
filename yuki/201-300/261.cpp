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

int N,K,Q;
int bar[1010],rev[1010];
int step[101][101],par[101],A[101];

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	ll lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	ll v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) bar[i]=i;
	cin>>K;
	FOR(i,K) {
		cin>>x>>y;
		swap(bar[x-1],bar[x]);
	}
	FOR(i,N) rev[bar[i]]=i;
	
	MINUS(step);
	FOR(i,N) {
		step[i][i]=0;
		par[i]=1;
		x=rev[i];
		while(x!=i) {
			step[i][x]=par[i]++;
			x=rev[x];
		}
	}
	
	cin>>Q;
	while(Q--) {
		pair<ll,ll> p(0,1);
		FOR(i,N) cin>>A[i], A[i]--;
		FOR(i,N) {
			if(step[A[i]][i]==-1) {
				cout<<-1<<endl;
				goto out;
			}
			p=crt(p.first,p.second,step[A[i]][i],par[A[i]]);
			if(p.first<0) {
				cout<<-1<<endl;
				goto out;
			}
		}
		if(p.first==0) p.first += p.second;
		cout<<p.first<<endl;
		
		out:
		;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

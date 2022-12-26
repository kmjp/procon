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


ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

ll inv(ll p,ll q) { // return (1/p)%q ( p,q is co-prime)
	ll xx,yy,g=ext_gcd(p,q,xx,yy);
	if(xx<0) xx+=q, yy-=p;
	return xx;
}


ll CRT_garner(vector<pair<ll,ll> > V, ll mo=1000000007) {
	const int prime_max = 40000;
	static int NP,prime[10000],divp[prime_max+3];
	int i,j,k,l,r,x,y; string s;
	int N=V.size();
	set<ll> P;
	vector<int> num;
	
	if(NP==0) {
		for(int i=2;i<prime_max;i++) if(divp[i]==0) {
			prime[NP++]=i;
			for(int j=i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
		}
	}
	FOR(i,N) {
		ll v=V[i].second;
		FOR(j,NP) if(v%prime[j]==0) {
			P.insert(prime[j]);
			while(v%prime[j]==0) v/=prime[j];
		}
		if(v>1) P.insert(v);
	}
	
	num=vector<int>(N,0);
	
	FORR(r,P) {
		y=0;
		FOR(x,N) {
			num[x]=1;
			j=V[x].second;
			while(j%r==0) j/=r, num[x]*=r;
			if(num[y]<num[x]) y=x;
		}
		FOR(x,N) if(x!=y) {
			if(V[x].first%num[x]!=V[y].first%num[x]) return -1;
			V[x].second /= num[x];
			V[x].first %= V[x].second;
		}
	}
	vector<pair<ll,ll> > V2;
	FOR(x,N) if(V[x].second>1) V2.emplace_back(V[x].second,V[x].first);
	sort(V2.begin(),V2.end());
	V=V2;
	N=V.size();
	
	// garner
	FOR(y,N) FOR(x,y) {
		ll k=V[y].second-V[x].second;
		if(k<0) k+=V[y].first;
		V[y].second = k*inv(V[x].first,V[y].first)%V[y].first;
	}
	ll ret=0;
	for(x=N-1;x>=0;x--) ret = (ret*V[x].first+V[x].second)%mo;
	return ret;
}

void solve() {
	
	int N,i,x,y,nz=0;
	vector<pair<ll,ll> > V;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		V.emplace_back(x,y);
		nz+=x>0;
	}
	
	if(nz==0) {
		FOR(y,N) FOR(x,y) V[y].second/=__gcd(V[x].second,V[y].second);
		ll ret=1;
		FOR(x,N) ret=ret*V[x].second%1000000007;
		cout<<ret<<endl;
	}
	else {
		cout << CRT_garner(V) << endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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

int N,M;
int A[101010];
int num[101010];
int used[101010];
ll tret[201010];
ll ret=1LL<<60;
typedef complex<double> Comp;

vector<Comp> fft(vector<Comp> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		double deg=(rev?-1:1) * 2*acos(-1)/m;
		Comp wr(cos(deg),sin(deg));
		for(i=0;i<n;i+=m) {
			Comp w(1,0);
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				Comp t1=v[j1],t2=w*v[j2];
				v[j1]=t1+t2, v[j2]=t1-t2;
				w*=wr;
			}
		}
	}
	if(rev) FOR(i,n) v[i]*=1.0/n;
	return v;
}

vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q,bool resize=false) {
	if(resize) {
		int s=2;
		while(s*2<P.size()+Q.size()) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,20) {
		ll tot=i;
		FOR(x,N) tot+=(M-A[x])%M, A[x]=A[x]*10%M;
		ret=min(ret,tot);
	}
	
	int alpha=__gcd(1<<20,M)*__gcd(125*125*125,M);
	if(alpha==M) return _P("%lld\n",ret);
	int per;
	
	FOR(i,N) num[A[i]]++;
	
	vector<vector<ll>> loops;
	for(i=alpha;i<M;i+=alpha) if(used[i]==0) {
		vector<Comp> nu,ad;
		int per;
		x = i;
		FOR(per,M) {
			used[x]=1;
			ad.push_back(M-x);
			nu.push_back(num[x]);
			x=x*10%M;
			if(x==i) break;
		}
		per++;
		reverse(ALL(nu));
		
		FOR(j,per) ad.push_back(ad[j]);
		auto prod = MultPoly(ad,nu,true);
		
		vector<ll> lp;
		FOR(j,per) lp.push_back((ll)(prod[per-1+j].real()+0.1));
		loops.push_back(lp);
	}
	
	int maxper=1;
	FORR(r,loops) maxper=maxper/__gcd(maxper,(int)r.size())*r.size();
	FOR(i,maxper) {
		ll tot=20+i;
		FORR(r,loops) tot += r[i%r.size()];
		ret=min(ret,tot);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

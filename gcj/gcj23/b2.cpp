#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

int W,N,D;
ll X[1010];

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
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	if(x<lcm) x+=lcm;
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>W>>N>>D;
	FOR(i,W) {
		cin>>X[i];
	}
	int g=__gcd(N,D);
	ll ret=0;
	for(int L=0,R=W-1;L<R;L++,R--) {
		ll a=X[L];
		ll b=X[R];
		
		auto p=crt((b-a+N)%N,N,0,D);
		if(p.first>=0) {
			ll x=p.first/D;
			ret+=min(x,N/g-x);
		}
		else {
			ret=1LL<<60;
		}
		
		
		
	}
	
	if(ret>=1LL<<60) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
	}
	else {
		cout<<"Case #"<<_loop<<": "<<ret<<endl;
	}
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}



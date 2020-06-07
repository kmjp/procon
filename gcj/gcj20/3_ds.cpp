#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D;
int X[2020],Y[2020];
double table[1<<15];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y;
	}
	
	assert(N==2);
	
	
	ll P,Q;
	ll DX=abs(X[0]-X[1]);
	ll DY=abs(Y[0]-Y[1]);
	if(DX<DY) swap(DX,DY);
	
	if(DX>=2*D) {
		P=0,Q=1;
	}
	else if(DX>=D) {
		ll H=D-(DY-D);
		ll W=D-(DX-D);
		ll A=1LL*2*D*2*D;
		P=3*H*W;
		Q=A+A-H*W;
	}
	else {
		ll H=D-(DY-D);
		ll W=D-(DX-D);
		ll A=1LL*2*D*2*D;
		ll C=4*DX*DY;
		Q=A+A-H*W;
		P=Q-C;
	}
	
	ll g=__gcd(P,Q);
	P/=g;
	Q/=g;
	
	_P("Case #%d: %lld %lld\n",_loop,P,Q);
}

void init() {
	int mask;
	int i,j;
	FOR(mask,1<<N) {
		vector<int> V;
		
		FOR(i,N) if(mask&(1<<i)) V.push_back(i);
		int ok=0,al=0;
		FOR(i,V.size()) FOR(j,i) al++, ok+=(V[i]+V[j]>=N);
		
		if(al) table[mask]=1.0*ok/al;
	}
	
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



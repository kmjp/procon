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

int N;
ll X[101],Y[101];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	if(N<=3) {
		_P("Case #%d: %d\n",_loop,N);
		return;
	}
	
	int ma=3;
	FOR(j,N) FOR(i,j) {
		map<pair<ll,ll>,int> M;
		if(X[i]==X[j]) {
			FOR(x,N) M[{X[x],1}]++;
		}
		else {
			ll dx=X[i]-X[j];
			ll dy=Y[i]-Y[j];
			if(dx<0) dx=-dx,dy=-dy;
			
			FOR(x,N) {
				ll p=Y[x]*dx-dy*X[x];
				ll q=dx;
				ll g=__gcd(p,q);
				p/=g;
				q/=g;
				M[{p,q}]++;
			}
		}
		int sum=0;
		int num=0;
		vector<int> C;
		FORR(m,M) {
			if(m.second%2==0) sum+=m.second;
			else C.push_back(m.second);
		}
		sort(ALL(C));
		while(C.size()>=2 && C[C.size()-2]>=3) {
			sum+=C.back();
			C.pop_back();
			sum+=C.back();
			C.pop_back();
		}
		
		if(C.size()==1) {
			sum+=C[0];
		}
		else if(C.size()>=2) {
			sum+=C.back();
			C.pop_back();
			sum+=C.back();
			C.pop_back();
		}
		
		ma=max(ma,sum);
		
	}
	
	
	_P("Case #%d: %d\n",_loop,ma);
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



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

vector<ll> V;
const ll T=1000000000;
const ll T2=120*1000000000LL;
const ll day=360*120*T;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	V.resize(3);
	cin>>V[0]>>V[1]>>V[2];
	sort(ALL(V));
	
	ll A,B,C,D;
	do {
		ll a;
		FOR(i,11) {
			ll a=i*T+((V[1]-V[0])%T+T)%T;
			if(a%11==0) {
				D=a/11;
				break;
			}
		}
		if(i==12) continue;
		
		A=((V[0]+day-D)%day+day)%day;
		B=((V[1]+day-12*D)%day+day)%day;
		C=((V[2]+day-720*D)%day+day)%day;
		FOR(i,12*60*60) {
			ll a=i*T%day;
			ll b=i*12*T%day;
			ll c=i*720*T%day;
			if((b-a+day)%day!=(B-A+day)%day) continue;
			if((c-b+day)%day!=(C-B+day)%day) continue;
			A=i/3600;
			B=i/60%60;
			C=i%60;
			break;
			
		}
		if(i<12*60*60) break;
		
		
		
		
	} while(next_permutation(ALL(V)));
	
	
	_P("Case #%d: %lld %lld %lld %lld\n",_loop,A,B,C,D);
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



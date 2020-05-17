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

ll L,R;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>L>>R;
	
	ll cur=1;
	while(L>=10*cur && R>=10*cur) {
		if(L>=R+cur) {
			for(i=31;i>=0;i--) {
				ll cnt=(cur+cur+(1LL<<i)-1)*(1LL<<i)/2;
				if(L-cnt>=R) {
					L-=cnt;
					cur+=1LL<<i;
				}
			}
			continue;
		}
		else if(R>=L+cur) {
			for(i=30;i>=0;i--) {
				ll cnt=(cur+cur+(1LL<<i)-1)*(1LL<<i)/2;
				if(R-cnt>=L) {
					R-=cnt;
					cur+=1LL<<i;
				}
			}
			continue;
		}
		else if(L>=R) {
			for(i=31;i>=0;i--) {
				ll a=cur*(1LL<<i)+2*(1LL<<i)*((1LL<<i)-1)/2;
				ll b=a+(1LL<<i);
				
				if(L>=a && R>=b) {
					L-=a;
					R-=b;
					cur+=(2LL<<i);
				}
			}
		}
		else {
			for(i=31;i>=0;i--) {
				ll a=cur*(1LL<<i)+2*(1LL<<i)*((1LL<<i)-1)/2;
				ll b=a+(1LL<<i);
				
				if(R>=a && L>=b) {
					R-=a;
					L-=b;
					cur+=(2LL<<i);
				}
			}
		}
	}
	while(L>=cur || R>=cur) {
		if(L>=R) {
			L-=cur;
			cur++;
		}
		else {
			R-=cur;
			cur++;
		}
	}
	
	_P("Case #%d: %lld %lld %lld\n",_loop,cur-1,L,R);
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



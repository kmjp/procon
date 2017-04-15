#include <bits/stdc++.h>
#include <sys/time.h>
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

ll HD,AD,HK,AK,B,D;

ll calc(int H,int A,int L) {
	if(A==0) return L;
	int T=(H+(A-1))/A;
	if(L<=T) return L;
	
	int ret=T;
	L-=T-1;
	H=HD-A;
	if(H<=0) return 1LL<<32;
	T=(H+(A-1))/A;
	
	if(T==1) {
		if(L==1) return ret+1;
		else return 1LL<<32;
	}
	return ret + L + (L-T+(T-2))/(T-1);
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>HD>>AD>>HK>>AK>>B>>D;
	
	ll mia=1LL<<31;
	FOR(i,1000000000) {
		ll at=AD+B*i;
		ll turn=i+(HK+(at-1))/at;
		mia=min(mia,turn);
		if(at>=HK || B==0) break;
		if(turn>mia) break;
	}
	
	ll ret=1LL<<32;
	ll turn=0;
	ll nh=HD;
	FOR(i,1000000000) {
		ret=min(ret,turn+calc(nh,AK,mia));
		if(AK<=0 || D==0) break;
		
		if(nh<=AK-D) {
			nh=HD-AK;
			turn++;
		}
		AK=max(AK-D,0LL);
		nh-=AK;
		turn++;
		if(nh<=0) break;
	}
	
	if(ret>=1LL<<32) _P("Case #%d: IMPOSSIBLE\n",_loop);
	else _P("Case #%d: %d\n",_loop,ret);
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



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

int N,P;
int G[101];


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	int num[5]={};
	
	cin>>N>>P;
	FOR(i,N) {
		cin>>x;
		num[x%P]++;
	}
	
	int ret=num[0];
	
	if(P==2) {
		ret += (num[1]+1)/2;
	}
	else if(P==3) {
		x = min(num[1],num[2]);
		ret += x;
		num[1]-=x;
		num[2]-=x;
		ret += (num[1]+2)/3;
		ret += (num[2]+2)/3;
	}
	else {
		x = min(num[1],num[3]);
		ret += x;
		num[1]-=x;
		num[3]-=x;
		ret += num[2]/2;
		num[2] %= 2;
		
		if(num[2]>0 && num[1]>=2) {
			ret++;
			num[1]-=2;
			num[2]=0;
		}
		if(num[2]>0 && num[3]>=2) {
			ret++;
			num[3]-=2;
			num[2]=0;
		}
		if(num[2]) {
			ret++;
		}
		else {
			ret += (num[1]+3)/4;
			ret += (num[3]+3)/4;
		}
	}
	
	
	
	_P("Case #%d: %d\n",_loop,ret);
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



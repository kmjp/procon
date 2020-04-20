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

int T,A,B;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	string s;
	
	int cx,cy;
	for(cx=-1000000000;cx<=1000000000;cx+=350000000) {
		for(cy=-1000000000;cy<=1000000000;cy+=350000000) {
			cout<<cx<<" "<<cy<<endl;
			cin>>s;
			if(s=="CENTER") return;
			if(s=="HIT") goto out;
		}
	}
	out:
	
	int L=cx,R=cx;
	for(i=30;i>=0;i--) {
		if(R+(1<<i)<=1000000000) {
			cout<<(R+(1<<i))<<" "<<cy<<endl;
			cin>>s;
			if(s=="CENTER") return;
			if(s=="HIT") R+=1<<i;
		}
		if(L-(1<<i)>=-1000000000) {
			cout<<(L-(1<<i))<<" "<<cy<<endl;
			cin>>s;
			if(s=="CENTER") return;
			if(s=="HIT") L-=1<<i;
		}
	}
	cx=(ll)(R+L)/2;
	int U=cy,D=cy;
	for(i=30;i>=0;i--) {
		if(D+(1<<i)<=1000000000) {
			cout<<cx<<" "<<(D+(1<<i))<<endl;
			cin>>s;
			if(s=="CENTER") return;
			if(s=="HIT") D+=1<<i;
		}
		if(U-(1<<i)>=-1000000000) {
			cout<<cx<<" "<<(U-(1<<i))<<endl;
			cin>>s;
			if(s=="CENTER") return;
			if(s=="HIT") U-=1<<i;
		}
	}
	cy=(ll)(U+D)/2;
	cout<<cx<<" "<<cy<<endl;
	cin>>s;
	assert(s=="CENTER");
	return;
	
	
	
	
}

void init() {
	cin>>A>>B;
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



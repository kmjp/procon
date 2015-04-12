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


int mult(int cur,char c) {
	int minu=(cur<0);
	cur=abs(cur);
	
	if(cur==1) {
		if(c=='i') cur=2;
		if(c=='j') cur=3;
		if(c=='k') cur=4;
	}
	else if(cur==2) {
		if(c=='i') cur=1, minu^=1;
		if(c=='j') cur=4;
		if(c=='k') cur=3, minu^=1;
	}
	else if(cur==3) {
		if(c=='i') cur=4, minu^=1;
		if(c=='j') cur=1, minu^=1;
		if(c=='k') cur=2;
	}
	else if(cur==4) {
		if(c=='i') cur=3;
		if(c=='j') cur=2, minu^=1;
		if(c=='k') cur=1, minu^=1;
	}
	
	if(minu) cur=-cur;
	return cur;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y; string s;
	ll L,X;
	string S;
	
	cin>>L>>X;
	cin>>s;
	
	if(X>8) X=8+(X-8)%4;
	S="";
	FOR(i,X) S+=s;
	
	int state=0, cv=1;
	FOR(i,S.size()) {
		cv=mult(cv,S[i]);
		if(state==0 && cv==2) state=1, cv=1;
		if(state==1 && cv==3) state=2, cv=1;
	}
	
	_P("Case #%d: %s\n",_loop,(state==2&&cv==4)?"YES":"NO");
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



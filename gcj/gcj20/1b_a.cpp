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

string hoge(int X,int Y) {
	if(abs(X)+abs(Y)==1) {
		if(X==1) return "E";
		if(X==-1) return "W";
		if(Y==1) return "N";
		if(Y==-1) return "S";
	}
	if(X==0 && Y==0) return "";
	if(abs(X)%2==0 && abs(Y)%2==1) {
		string s=hoge(X/2,(Y+1)/2);
		if(s!="IMPOSSIBLE") return "S"+s;
		s=hoge(X/2,(Y-1)/2);
		if(s!="IMPOSSIBLE") return "N"+s;
	}
	if(abs(X)%2==1 && abs(Y)%2==0) {
		string s=hoge((X+1)/2,Y/2);
		if(s!="IMPOSSIBLE") return "W"+s;
		s=hoge((X-1)/2,Y/2);
		if(s!="IMPOSSIBLE") return "E"+s;
	}
	return "IMPOSSIBLE";
	
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int X,Y;
	cin>>X>>Y;
	string S=hoge(X,Y);
	_P("Case #%d: %s\n",_loop,S.c_str());
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



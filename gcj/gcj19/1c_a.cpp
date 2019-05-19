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


int T;
int N;
string ST[505];

string hoge(int p,int PL,int PR) {
	if(PR<=PL) return "";
	int R=0,P=0,S=0;
	int LP=505,RP=-1,LR=505,RR=-1,LS=505,RS=-1;
	int i;
	for(i=PL;i<PR;i++) {
		if(ST[i][p]=='P') P++, LP=min(LP,i), RP=max(RP,i+1);
		if(ST[i][p]=='R') R++, LR=min(LR,i), RR=max(RR,i+1);
		if(ST[i][p]=='S') S++, LS=min(LS,i), RS=max(RS,i+1);
	}
	if(P&&R&&S) return "IMPOSSIBLE";
	if(P&&!R&&!S) return "S";
	if(!P&&R&&!S) return "P";
	if(!P&&!R&&S) return "R";
	
	if(P&&R&&!S) {
		string s=hoge(p+1,LP,RP);
		if(s=="IMPOSSIBLE") return s;
		return "P"+s;
	}
	if(P&&!R&&S) {
		string s=hoge(p+1,LS,RS);
		if(s=="IMPOSSIBLE") return s;
		return "S"+s;
	}
	if(!P&&R&&S) {
		string s=hoge(p+1,LR,RR);
		if(s=="IMPOSSIBLE") return s;
		return "R"+s;
	}
	
	return "";
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		cin>>ST[i];
		while(ST[i].size()<500) ST[i]+=ST[i];
	}
	sort(ST,ST+N);
	string ret=hoge(0,0,N);
	
	_P("Case #%d: %s\n",_loop,ret.c_str());
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



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
vector<string> V[101];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		string S;
		cin>>S;
		V[i].clear();
		V[i].push_back("");
		FORR(c,S) {
			if(c=='*') {
				V[i].push_back("");
			}
			else {
				V[i].back().push_back(c);
			}
		}
	}
	string pre="",suf="";
	FOR(i,N) {
		if(V[i][0].size()>pre.size()) pre=V[i][0];
		if(V[i].back().size()>suf.size()) suf=V[i].back();
	}
	int ok=1;
	FOR(i,N) {
		if(pre.substr(0,V[i][0].size())!=V[i][0]) ok=0;
		if(suf.substr(suf.size()-V[i].back().size())!=V[i].back()) ok=0;
	}
	
	if(ok==0) {
		_P("Case #%d: *\n",_loop);
	}
	else {
		string T;
		T=pre;
		FOR(i,N) {
			for(j=1;j<V[i].size()-1;j++) T+=V[i][j];
		}
		T+=suf;
		_P("Case #%d: %s\n",_loop,T.c_str());
	}
	
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



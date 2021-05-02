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

string S,E;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>S>>E;
	
	if(S==E) {
		_P("Case #%d: 0\n",_loop);
		return;
	}
	int ret=0;
	if(S=="0") S="1", ret++;
	vector<int> V={1},W={1};
	FOR(i,S.size()) if(i) {
		if(S[i]==S[i-1]) V.back()++;
		else V.push_back(1);
	}
	
	FOR(i,E.size()) if(i) {
		if(E[i]==E[i-1]) W.back()++;
		else W.push_back(1);
	}
	if(E=="0") {
		_P("Case #%d: %d\n",_loop,(int)V.size());
		return;
	}
	int mi=1<<20;
	for(i=0;i<=V.size();i++) {
		int over=i+W.size()-V.size();
		int can=i;
		if(V.size()%2==1) can++;
		if(over<0) continue;
		if(can<over) continue;
		int count=i+ret;
		FOR(j,W.size()) {
			if(i+j<V.size()) {
				if(V[i+j]!=W[j]) {
					if(i+j==V.size()-1&&(V.size()%2==0||V.size()>W.size())&&W[j]>=V[i+j]) count+=W[j]-V[i+j];
					else count+=1<<20;
				}
			}
			else {
				count+=W[j];
			}
		}
		mi=min(mi,count);
	}
	
	
	
	if(mi==1<<20) {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
	}
	else {
		_P("Case #%d: %d\n",_loop,mi);
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



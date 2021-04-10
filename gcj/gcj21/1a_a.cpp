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
string X;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	string P;
	int ret=0;
	
	FOR(i,N) {
		cin>>X;
		
		if(X.size()<=P.size()) {
			if(X<P.substr(0,X.size())) {
				while(X.size()<=P.size()) X+='0', ret++;
			}
			else if(X>P.substr(0,X.size())) {
				while(X.size()<P.size()) X+='0', ret++;
			}
			else {
				string T=P.substr(X.size());
				for(j=T.size()-1;j>=0;j--) {
					if(T[j]!='9') {
						T[j]++;
						for(x=j+1;x<T.size();x++) T[x]='0';
						break;
					}
				}
				if(j==-1) {
					T=string(T.size()+1,'0');
				}
				
				ret+=T.size();
				X=X+T;
				
			}
		}
		P=X;
		
	}
	
	
	_P("Case #%d: %d\n",_loop, ret);
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



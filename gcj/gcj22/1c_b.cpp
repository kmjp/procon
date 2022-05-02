#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N,K;
ll E[1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K;
	ll s1=0,s2=0;
	FOR(i,N) {
		cin>>E[i];
		s2+=E[i]*s1;
		s1+=E[i];
	}
	
	if(K==1) {
		if(s1==0) {
			if(s2==0) {
				cout<<"Case #"<<_loop<<": 0"<<endl;
			}
			else {
				cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
			}
		}
		else if(s2%s1==0) {
			ll D=-s2/s1;
			cout<<"Case #"<<_loop<<": "<<D<<endl;
			
		}
		else {
			cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
		}
	}
	else {
		for(int d=-2000000;d<=2000000;d++) {
			ll t2=s2+d*s1;
			ll t1=s1+d;
			if(t1==0) {
				if(t2==0) {
					cout<<"Case #"<<_loop<<": 0 "<<d<<endl;
					return;
				}
			}
			else if(t2%t1==0) {
				ll D=-t2/t1;
				cout<<"Case #"<<_loop<<": "<<D<<" "<<d<<endl;
				return;
			}
		}
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
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



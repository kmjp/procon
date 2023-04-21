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
int A[101010];
pair<int,int> P[101010];
set<pair<int,int>> L,R;
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	
	L.clear();
	R.clear();
	for(i=N-1;i>=0;i--) {
		x=P[i].first;
		auto it=R.lower_bound({x+K,0});
		if(it==R.end()) {
			y=1;
		}
		else {
			y=it->second+1;
		}
		R.insert({x,y});
	}
	FOR(i,N) {
		x=P[i].first;
		auto it=L.lower_bound({x-K+1,0});
		if(it==L.begin()) {
			y=1;
		}
		else {
			y=(--it)->second+1;
		}
		L.insert({x,y});
	}
	cout<<"Case #"<<_loop<<":";
	FOR(i,N) {
		x=A[i];
		y=1;
		auto it=R.lower_bound({x+K,0});
		if(it!=R.end()) y+=it->second;
		it=L.lower_bound({x-K+1,0});
		if(it!=L.begin()) y+=(--it)->second;
		cout<<" "<<y;
		
	}
	cout<<endl;
	
	
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



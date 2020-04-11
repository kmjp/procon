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

ll N;

static const int N_=1020;
static ll C_[N_][N_];

void solve(int _loop) {
	int f,i,j,k,l,x,y,r;
	
	cin>>N;
	
	vector<pair<int,int>> R;
	for(x=0;x<=35;x++) {
		ll lef=N-(x+1);
		R.clear();
		int side=0;
		
		for(y=x;y>=0;y--) {
			if(lef>=(1LL<<y)-1) {
				lef-=(1LL<<y)-1;
				if(side==0) {
					FOR(i,y+1) R.push_back({y,i});
				}
				else {
					FOR(i,y+1) R.push_back({y,y-i});
				}
				side^=1;
			}
			else {
				if(side==0) {
					R.push_back({y,0});
				}
				else {
					R.push_back({y,y});
				}
			}
		}
		if(lef==0) break;
	}
	assert(x<36);
	
	reverse(ALL(R));
	ll sum=0;
	
	_P("Case #%d:\n",_loop);
	FORR(r,R) {
		_P("%d %d\n",r.first+1,r.second+1);
		sum+=C_[r.first][r.second];
	}
	//_P("%lld %lld\n",N,sum);
	assert(N==sum);
}

void init() {
	int i,j;
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=min(1LL<<40,C_[i-1][j-1]+C_[i-1][j]);
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



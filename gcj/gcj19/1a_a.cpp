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

int H,W;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>H>>W;
	int rev=0;
	vector<pair<int,int>> R;
	if(H>W) {
		swap(H,W);
		rev=1;
	}
	
	if(H==2) {
		if(W<5) {
			_P("Case #%d: IMPOSSIBLE\n",_loop);
			return;
		}
		x=1;
		R.push_back({1,x});
		while(x+3<=W) {
			R.push_back({2,x+3});
			x++;
			R.push_back({1,x});
		}
		R.push_back({2,1});
		R.push_back({1,W-1});
		R.push_back({2,2});
		R.push_back({1,W});
		R.push_back({2,3});
		
	}
	else if(H==3) {
		vector<int> C;
		if(W<4) {
			_P("Case #%d: IMPOSSIBLE\n",_loop);
			return;
		}
		FOR(x,W) {
			R.push_back({1,x+1});
			R.push_back({2,(x+2)%W+1});
			R.push_back({3,x+1});
		}
	}
	else if(H==4&&W==4) {
		R.push_back({1,1});		R.push_back({2,3});		R.push_back({3,1});		R.push_back({4,3});
		R.push_back({1,2});		R.push_back({2,4});		R.push_back({3,2});		R.push_back({4,4});
		R.push_back({1,3});		R.push_back({2,1});		R.push_back({3,3});		R.push_back({4,1});
		R.push_back({3,4});		R.push_back({2,2});		R.push_back({1,4});		R.push_back({4,2});
	}
	else {
		int vis[20]={};
		y=0;
		FOR(i,H) {
			while(vis[y]) y=(y+1)%H;
			vis[y]=1;
			FOR(x,W) {
				R.push_back({y+1,x+1});
				y=(y+2)%H;
			}
		}
	}
	if(rev) {
		swap(H,W);
		FORR(r,R) swap(r.first,r.second);
	}
	
	_P("Case #%d: POSSIBLE\n",_loop);
	FORR(r,R) _P("%d %d\n",r.first,r.second);
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



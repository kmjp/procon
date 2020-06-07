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

string A,B;
int N,M;

int dp[61][61];
pair<int,int> nex[61][61];
int hoge(int x,int y) {
	if(dp[x][y]>=0) return dp[x][y];
	if(x==N&&y==M) return 0;
	dp[x][y]=101010;
	if(x<N) {
		if(dp[x][y]>1+hoge(x+1,y)) {
			dp[x][y]=min(dp[x][y],1+hoge(x+1,y));
			nex[x][y]={x+1,y};
		}
	}
	if(y<M) {
		if(dp[x][y]>1+hoge(x,y+1)) {
			dp[x][y]=min(dp[x][y],1+hoge(x,y+1));
			nex[x][y]={x,y+1};
		}
	}
	if(x<N&&y<M) {
		if(dp[x][y]>(A[x]!=B[y])+hoge(x+1,y+1)) {
			dp[x][y]=min(dp[x][y],(A[x]!=B[y])+hoge(x+1,y+1));
			nex[x][y]={x+1,y+1};
		}
	}
	return dp[x][y];
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>A>>B;
	N=A.size();
	M=B.size();
	MINUS(dp);
	hoge(0,0);
	int dif=0;
	x=y=0;
	string R[2];
	while(x<N||y<M) {
		
		if(nex[x][y].first==x+1 && nex[x][y].second==y+1) {
			if(A[x]==B[y]) {
				R[0]+=A[x];
				R[1]+=A[x];
			}
			else {
				if(dif==0) {
					R[0]+=B[y];
					R[1]+=A[x];
				}
				else {
					R[1]+=B[y];
					R[0]+=A[x];
				}
				dif^=1;
			}
			x++;
			y++;
		}
		else if(nex[x][y].first==x+1) {
			if(dif==0) {
				R[1]+=A[x];
			}
			else {
				R[0]+=A[x];
			}
			dif^=1;
			x++;
		}
		else {
			if(dif==0) {
				R[0]+=B[y];
			}
			else {
				R[1]+=B[y];
			}
			dif^=1;
			y++;
		}
	}
	
	if(R[0].empty()) swap(R[0],R[1]);
	_P("Case #%d: %s\n",_loop,R[0].c_str());
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



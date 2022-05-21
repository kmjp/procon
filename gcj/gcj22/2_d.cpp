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


int N,C;
ll dp[101010];
ll S[2][101010];

ll go(vector<pair<int,int>> X) {
	if(X.empty()) return 0;
	int N=X.size();
	sort(ALL(X));
	int i;
	FOR(i,N) {
		S[0][i+1]=S[0][i];
		S[1][i+1]=S[1][i];
		S[X[i].second][i+1]+=X[i].first;
	}
	
	map<int,int> M;
	int cur=0;
	M[0]=0;
	dp[0]=0;
	
	for(i=1;i<=N;i++) {
		int x=X[i-1].first;
		int c=X[i-1].second;
		dp[i]=dp[i-1]+2*x;
		if(i>=2) dp[i]=min(dp[i],dp[i-2]+2*x+(c==X[i-2].second)*C);
		
		if(c==1) cur++;
		else cur--;
		
		if(M.count(cur)) {
			int k=M[cur];
			dp[i]=min(dp[i],dp[k]+2*(S[c][i]-S[c][k]));
		}
		M[cur]=i;
	}
	
	
	return dp[N];
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>C;
	vector<pair<int,int>> X,Y;
	FOR(i,N) {
		cin>>x>>y;
		if(x>0) X.push_back({x,y});
		else Y.push_back({-x,y});
	}
	
	ll ret=go(X)+go(Y);
	cout<<"Case #"<<_loop<<": "<<ret<<endl;
	//_P("Case #%d:\n",_loop);
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



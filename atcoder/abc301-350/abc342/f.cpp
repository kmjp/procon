#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int N,L,D;

double dp[402020],S[404040];
double win[404040];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<double,20> AS,BS,winS;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>D;
	
	dp[0]=1;
	dp[1]=-1;
	for(y=0;y<=N;y++) {
		if(y) dp[y]+=dp[y-1];
		if(y<L) {
			dp[y+1]+=dp[y]/D;
			dp[y+D+1]-=dp[y]/D;
		}
		if(y>=L) {
			BS.add(y,dp[y]);
		}
	}
	
	for(i=N;i>=0;i--) {
		//‰½‚à‚µ‚È‚¢
		double nomove=1-(BS(N)-BS(i-1));
		double move=(winS(i+D)-winS(i))/D;
		win[i]=max(move,nomove);
		winS.add(i,win[i]);
		
	}
	_P("%.12lf\n",win[0]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

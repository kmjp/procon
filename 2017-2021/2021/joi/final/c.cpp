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

int N;
int H[5050];
int R[5050];
int dp[5050];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,13> smaller;
int S[5050],L[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(x,5050) dp[x]=1<<30;
	dp[0]=0;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i];
		R[H[i]]=i;
	}
	
	FOR(i,N) {
		ZERO(larger.bit);
		ZERO(smaller.bit);
		for(j=i+1;j<=N;j++) {
			x=R[j];
			S[j]=smaller(N)-smaller(x);
			smaller.add(x,1);
		}
		
		int sum=0;
		FOR(j,N) {
			L[H[j]]=sum;
			if(H[j]>i) sum++;
		}
		sum=0;
		for(j=i+1;j<=N;j++) {
			x=R[j];
			sum+=L[j]-S[j];
			dp[j]=min(dp[j],dp[i]+sum);
		}
	}
	
	cout<<dp[N]<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

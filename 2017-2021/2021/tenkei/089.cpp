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

ll mo=1000000007;
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N;
ll K;
int A[202020];

ll dp[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<int> V;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(A[i]);
	}
	sort(ALL(V));
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
	}
	dp[0]=1;
	dp[1]=mo-1;
	ll S=0;
	for(int L=0,R=0;L<N;L++) {
		if(L) (dp[L]+=dp[L-1])%=mo;
		while(R<N) {
			int add=bt(202020)-bt(A[R]);
			if(S+add>K) break;
			S+=add;
			bt.add(A[R],1);
			R++;
		}
		(dp[L+1]+=dp[L])%=mo;
		(dp[R+1]+=mo-dp[L])%=mo;
		S-=bt(A[L]-1);
		bt.add(A[L],-1);
		
	}
	
	dp[N]+=dp[N-1];
	cout<<dp[N]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

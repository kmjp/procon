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
int A[101010];
int B[101010];
int dp[101010];
int from[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) dp[i]=1<<29;
	for(i=2;i<=N;i++) cin>>A[i];
	for(i=3;i<=N;i++) cin>>B[i];
	dp[1]=0;
	for(i=2;i<=N;i++) {
		dp[i]=min(dp[i-1]+A[i],dp[i-2]+B[i]);
		if(dp[i-1]+A[i]<dp[i-2]+B[i]) {
			from[i]=1;
		}
		else {
			from[i]=2;
		}
	}
	vector<int> V={N};
	while(V.back()>1) {
		V.push_back(V.back()-from[V.back()]);
	}
	reverse(ALL(V));
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
int H[202020];
int dp[202020];
int from[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i];
		dp[i]=1<<30;
	}
	dp[0]=0;
	FOR(i,N-1) {
		for(j=1;j<=2;j++) if(chmin(dp[i+j],dp[i]+abs(H[i]-H[i+j]))) from[i+j]=i;
	}
	
	vector<int> V={N-1};
	while(V.back()) V.push_back(from[V.back()]);
	reverse(ALL(V));
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v+1<<" ";
	cout<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

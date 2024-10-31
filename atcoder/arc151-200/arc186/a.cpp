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

int N,Q;
int ret[9090];

int dp[31][31][959];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	dp[0][0][0]=1;
	for(int h=0;h<=N;h++) for(int w=0;w<=N;w++) for(int s=0;s<=h*w;s++) if(dp[h][w][s]) {
		ret[s]=1;
		for(int y2=2;h+y2<=N;y2++) for(int x2=2;w+x2<=N;x2++) dp[h+y2][w+x2][s+y2*x2]=1;
		
	}
	
	
	while(Q--) {
		cin>>x;
		if(ret[N*N-x]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

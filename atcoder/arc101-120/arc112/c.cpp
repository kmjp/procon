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
int P[202020];
vector<int> E[202020];

int dp[202020];
int C[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	for(i=N-1;i>=0;i--) {
		C[i]++;
		if(i) C[P[i]]+=C[i];
		int evenp=0,evenm=0;
		vector<int> odd;
		int sum=0;
		FORR(c,E[i]) {
			if(C[c]%2==0) {
				if(dp[c]-1>0) evenp+=dp[c]-1;
				if(dp[c]-1<0) evenm+=dp[c]-1;
			}
			else {
				odd.push_back(dp[c]-1);
			}
		}
		dp[i]=evenp;
		int turn=0;
		sort(ALL(odd));
		reverse(ALL(odd));
		FORR(o,odd) {
			if(turn==0) dp[i]+=o;
			else dp[i]-=o;
			turn^=1;
		}
		if(turn==0) dp[i]+=evenm;
		else dp[i]-=evenm;
	}
	int my=1-dp[0];
	cout<<(N+my)/2<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

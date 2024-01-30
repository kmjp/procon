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
int P[101010];
vector<int> E[101010];

int dp[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	
	int ma=1;
	for(i=N-1;i>=0;i--) {
		if(E[i].size()==0) {
			dp[i][0]=1;
			dp[i][1]=0;
		}
		else if(E[i].size()==1) {
			dp[i][0]=dp[E[i][0]][0]+1;
			dp[i][1]=dp[E[i][0]][1];
		}
		else {
			FORR(e,E[i]) {
				//�Œ��P�[�X
				dp[i][0]=max(dp[i][0],dp[e][0]+1);
				//�a�����P�[�X
				dp[i][1]+=max(dp[e][0],dp[e][1]);
			}
		}
		
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<max(dp[0][0],dp[0][1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

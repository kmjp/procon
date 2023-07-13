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
ll dp[4][4];
int A[202020];
string S;
ll ret=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>S;
	ll ret=0;
	FOR(i,N) {
		if(S[i]=='M') {
			dp[A[i]][3]++;
		}
		if(S[i]=='E') {
			dp[0][A[i]]+=dp[0][3];
			dp[1][A[i]]+=dp[1][3];
			dp[2][A[i]]+=dp[2][3];
		}
		if(S[i]=='X') {
			FOR(x,3) FOR(y,3) {
				k=0;
				while(k==x||k==y||k==A[i]) k++;
				ret+=k*dp[x][y];
			}
		}
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

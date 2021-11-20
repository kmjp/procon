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

ll dp[31][31][31][1000];

int A,B,C;
int K;
string S;
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0][0][0]=1;
	cin>>S>>K;
	FORR(c,S) {
		if(c=='K') A++,c=0;
		if(c=='E') B++,c=1;
		if(c=='Y') C++,c=2;
	}
	int a,b,c;
	FOR(a,A+1) FOR(b,B+1) FOR(c,C+1) {
		FOR(i,3) {
			if(i==0&&a+1>A) continue;
			if(i==1&&b+1>B) continue;
			if(i==2&&c+1>C) continue;
			int step=0;
			int s[3]={a,b,c};
			FORR(d,S) {
				if(s[d]>0) {
					s[d]--;
				}
				else {
					if(d==i) break;
					step++;
				}
			}
			FOR(j,1000) if(dp[a][b][c][j]) {
				if(i==0) dp[a+1][b][c][j+step]+=dp[a][b][c][j];
				if(i==1) dp[a][b+1][c][j+step]+=dp[a][b][c][j];
				if(i==2) dp[a][b][c+1][j+step]+=dp[a][b][c][j];
			}
		}
	}
	ll ret=0;
	for(i=0;i<=min(K,999);i++) ret+=dp[A][B][C][i];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

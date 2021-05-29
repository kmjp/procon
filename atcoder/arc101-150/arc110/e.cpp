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
string S;
int xo[1202020];
const ll mo=1000000007;
ll dp[1202020];
int num[1202020][4];
int ne[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		S[i]=S[i]-'A'+1;
		num[i][S[i]]=1;
		xo[i+1]=xo[i]^S[i];
	}
	
	
	MINUS(ne);
	ne[xo[N]]=N;
	num[N][1]=num[N][2]=num[N][3]=1;
	for(i=N-1;i>=0;i--) {
		
		FOR(j,4) num[i][j]&=num[i+1][j];
		int add=0;
		// ‘SÁ‚µ
		if((xo[N]^xo[i])>0&&((i==N-1)||(num[i][1]==0&&num[i][2]==0&&num[i][3]==0))) {
			add=1;
		}
		
		for(j=1;j<4;j++) {
			x=xo[i]^j;
			int t=ne[x];
			if(t==-1||t==N) continue;
			for(y=1;y<4;y++) if(num[t][y]) break;
			if(j==y&&t==i+1) {
				dp[i]+=1;
			}
			else if(y<4) {
				dp[i]+=1+(N-t)/2;
				if((N-t)%2==0) add=0;
			}
			else {
				dp[i]+=dp[t];
			}
			
			
		}
		dp[i]+=add;
		dp[i]%=mo;
		ne[xo[i]]=i;
	}
	cout<<dp[0]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

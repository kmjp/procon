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

int N,A,B;
int D[2020];

bitset<1800*2008> dp[2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	int S=0;
	FOR(i,N) {
		cin>>D[i];
		S+=D[i];
	}
	if(abs(A)+abs(B)>S) return _P("No\n");
	
	vector<int> T[2];
	FOR(y,2) {
		dp[0].reset();
		dp[0][0]=1;
		FOR(i,N) dp[i+1]=dp[i]|(dp[i]<<D[i]);
		x=(S+A+(y==0?B:-B));
		if(x%2) return _P("No\n");
		x/=2;
		if(dp[N][x]==0) return _P("No\n");
		for(i=N-1;i>=0;i--) {
			assert(dp[i+1][x]);
			if(dp[i][x]) {
				T[y].push_back(0);
			}
			else {
				T[y].push_back(1);
				x-=D[i];
			}
		}
		assert(x==0);
	}
	reverse(ALL(T[0]));
	reverse(ALL(T[1]));
	string ret;
	FOR(i,N) {
		if(T[0][i]==0&&T[1][i]==0) ret+="L";
		if(T[0][i]==0&&T[1][i]==1) ret+="D";
		if(T[0][i]==1&&T[1][i]==0) ret+="U";
		if(T[0][i]==1&&T[1][i]==1) ret+="R";
	}
	cout<<"Yes"<<endl;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

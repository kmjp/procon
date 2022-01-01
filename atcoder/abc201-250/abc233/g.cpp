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
string S[55];
int A[55][55];

int memo[55][55][55][55];

int dfs(int L,int T,int R,int B) {
	if(memo[L][T][R][B]>=0) return memo[L][T][R][B];
	if(A[R][B]-A[L][B]-A[R][T]+A[L][T]==0) {
		return memo[L][T][R][B]=0;
	}
	int ret=max((R-L),(B-T));
	
	int x,y;
	for(x=L+1;x<R;x++) ret=min(ret,dfs(L,T,x,B)+dfs(x,T,R,B));
	for(y=T+1;y<B;y++) ret=min(ret,dfs(L,T,R,y)+dfs(L,y,R,B));
	
	
	return memo[L][T][R][B]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) {
			A[y+1][x+1]=A[y+1][x]+A[y][x+1]-A[y][x]+(S[y][x]=='#');
		}
	}
	MINUS(memo);
	
	cout<<dfs(0,0,N,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

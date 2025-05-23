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

int N,M;
int C[10];
vector<int> A[101];

int num[10];
ll ret;
void dfs(int cur) {
	if(cur==N) {
		int cnt[101]={};
		int i;
		ll sum=0;
		FOR(i,N) {
			FORR(v,A[i]) cnt[v]+=num[i];
			sum+=num[i]*C[i];
		}
		int ok=1;
		FOR(i,M) if(cnt[i]<2) ok=0;
		
		if(ok) ret=min(ret,sum);
		
		return;
	}
	num[cur]=0;
	dfs(cur+1);
	num[cur]=1;
	dfs(cur+1);
	num[cur]=2;
	dfs(cur+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	ret=1LL<<60;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i];
	FOR(i,M) {
		cin>>x;
		FOR(y,x) {
			cin>>j;
			A[j-1].push_back(i);
		}
	}
	dfs(0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

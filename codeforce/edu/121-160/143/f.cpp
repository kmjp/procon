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

int T,N;
vector<int> E[202020];
int K;
int C[202020];
vector<int> A;
int ok;
int dfs(int cur,int pre) {
	int ma=0;
	int req=C[cur];
	FORR(e,E[cur]) if(e!=pre) {
		int ret=dfs(e,cur);
		if(ret<0) {
			if(req) {
				ok=0;
				return 0;
			}
			req=-ret;
		}
		else {
			ma=max(ma,ret);
		}
	}
	if(req==0) return ma+1;
	else if(req<=ma+1) return 0;
	else return -req+1;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			C[i]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		cin>>K;
		A.resize(K);
		FOR(i,K) {
			cin>>x;
			A[i]=x-1;
		}
		int L=0,R=N-K+1;
		while(L+1<R) {
			int M=(L+R)/2;
			FOR(i,K) C[A[i]]=1;
			FOR(i,M) C[A[i%K]]++;
			ok=1;
			if(dfs(0,0)>=0&&ok) L=M;
			else R=M;
		}
		cout<<L<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
ll M;


ll dfs(vector<int> A,int M,int d) {
	if(d==0||M==0) return 0;
	ll ret=0;
	vector<int> B[2];
	int m=(1<<(d-1));
	FORR(a,A) {
		if(a&m) {
			a-=m;
			B[1].push_back(a);
		}
		else B[0].push_back(a);
	}
	
	if(M==1<<d) {
		if(B[0].size()&&B[1].size()) {
			ret=dfs(B[0],m,d-1)+dfs(B[1],m,d-1);
		}
		else {
			ret=2*dfs(A,m,d-1)+1LL*m*m;
		}
		return ret;
	}
	if(B[0].size()) {
		ret=dfs(B[0],min(M,m),d-1);
	}
	else {
		ret=dfs(B[1],min(M,m),d-1)+(1LL*m)*min(M,m);
	}
	if(M>m) {
		if(B[1].size()) {
			ret+=dfs(B[1],M-m,d-1);
		}
		else {
			ret+=dfs(B[0],M-m,d-1)+(1LL*m)*(M-m);
		}
	}
	
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> A(N);
	FOR(i,N) cin>>A[i];
	
	cout<<dfs(A,M,30)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

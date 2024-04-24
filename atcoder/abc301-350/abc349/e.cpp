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

ll A[9];
int p3[10];

const int D=3*3*3*3*3*3*3*3*3;
int memo[D];

int encode(vector<int> v) {
	int ret=0;
	int y,x;
	FOR(y,9) ret+=v[y]*p3[y];
	return ret;
}
vector<int> decode(int v) {
	vector<int> R(9);
	int y;
	FOR(y,9) R[y]=v/p3[y]%3;
	return R;
}

int dfs(int cur) {
	if(memo[cur]!=-1) return memo[cur];
	vector<int> V=decode(cur);
	
	int y,x;
	if(V[0]==1&&V[1]==1&&V[2]==1) return memo[cur]=0;
	if(V[3]==1&&V[4]==1&&V[5]==1) return memo[cur]=0;
	if(V[6]==1&&V[7]==1&&V[8]==1) return memo[cur]=0;
	if(V[0]==1&&V[3]==1&&V[6]==1) return memo[cur]=0;
	if(V[1]==1&&V[4]==1&&V[7]==1) return memo[cur]=0;
	if(V[2]==1&&V[5]==1&&V[8]==1) return memo[cur]=0;
	if(V[0]==1&&V[4]==1&&V[8]==1) return memo[cur]=0;
	if(V[2]==1&&V[4]==1&&V[6]==1) return memo[cur]=0;
	if(V[0]==2&&V[1]==2&&V[2]==2) return memo[cur]=1;
	if(V[3]==2&&V[4]==2&&V[5]==2) return memo[cur]=1;
	if(V[6]==2&&V[7]==2&&V[8]==2) return memo[cur]=1;
	if(V[0]==2&&V[3]==2&&V[6]==2) return memo[cur]=1;
	if(V[1]==2&&V[4]==2&&V[7]==2) return memo[cur]=1;
	if(V[2]==2&&V[5]==2&&V[8]==2) return memo[cur]=1;
	if(V[0]==2&&V[4]==2&&V[8]==2) return memo[cur]=1;
	if(V[2]==2&&V[4]==2&&V[6]==2) return memo[cur]=1;
	
	int step=0;
	ll sum=0;
	FOR(y,9) {
		if(V[y]) {
			step++;
			if(V[y]==1) sum+=A[y];
			else sum-=A[y];
		}
	}
	if(step==9) {
		if(sum>0) return memo[cur]=0;
		else return memo[cur]=1;
	}
	
	if(step%2==0) {
		int ret=1;
		FOR(y,9) if(V[y]==0) {
			V[y]=1;
			ret=min(ret,dfs(encode(V)));
			V[y]=0;
		}
		memo[cur]=ret;
		
	}
	else {
		int ret=0;
		FOR(y,9) if(V[y]==0) {
			V[y]=2;
			ret=max(ret,dfs(encode(V)));
			V[y]=0;
		}
		memo[cur]=ret;
	}
	return memo[cur];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	FOR(i,9) cin>>A[i];
	p3[0]=1;
	FOR(i,9) p3[i+1]=p3[i]*3;
	
	
	x=dfs(0);
	if(x==0) {
		cout<<"Takahashi"<<endl;
	}
	else {
		cout<<"Aoki"<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

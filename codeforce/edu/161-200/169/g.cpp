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

struct node {
	int len;
	ll dp[10][10];
};

int N,K;
string S;

node A[404040];
node L[404040];
node R[404040];

node merge(node& L,node& R) {
	if(L.len==0) return R;
	if(R.len==0) return L;
	node M;
	M.len=L.len+R.len;
	int i,j,k;
	FOR(i,10) FOR(j,10) M.dp[i][j]=1LL<<50;
	
	FOR(i,10) FOR(j,10) FOR(k,10) {
		chmin(M.dp[i][k],L.dp[i][j]+R.dp[j][k]);
	}
	return M;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,404040) {
		node& n=A[i];
		if(i<N) {
			n.len=1;
			FOR(j,10) FOR(k,10) n.dp[j][k]=1LL<<50;
			for(j=1;j<10;j++) {
				n.dp[j][j]=j;
				n.dp[j][0]=j;
			}
			n.dp[0][S[i]-'0']=0;
			
		}
		else {
			n.len=0;
		}
	}
	int NB=(N+K-1)/K;
	FOR(i,NB) {
		FOR(j,K) {
			if(j==0) {
				L[i*K+j]=A[i*K];
				R[i*K+j]=A[i*K+K-1];
			}
			else {
				L[i*K+j]=merge(L[i*K+j-1],A[i*K+j]);
				R[i*K+j]=merge(A[i*K+K-1-j],R[i*K+j-1]);
			}
		}
	}
	
	for(i=0;i+K<=N;i++) {
		if(i%K==0) {
			auto v=L[i+(K-1)];
			cout<<v.dp[0][0]<<" ";
		}
		else {
			auto a=R[i/K*K+(K-1-i%K)];
			auto b=L[i/K*K+K+(i%K-1)];
			auto c=merge(a,b);
			cout<<c.dp[0][0]<<" ";
		}
	}
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

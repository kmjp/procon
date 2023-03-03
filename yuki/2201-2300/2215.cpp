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

int N,M,K;
int A[402020];

int L[404040][101];
int R[404040][101];

const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	
	if(M==1) {
		FOR(i,N) {
			cout<<(A[i]==0)<<endl;
		}
		return;
	}
	
	int ON=N;
	N=(N+M-1)/M*M;
	FOR(i,N) {
		if(i%M==0) {
			ZERO(L[i]);
			L[i][0]=1;
		}
		FOR(j,K) {
			(L[i+1][j]+=L[i][j])%=mo;;
			(L[i+1][(j+A[i])%K]+=L[i][j])%=mo;
		}
	}
	for(i=N;i>=1;i--) {
		if(i%M==0) {
			ZERO(R[i]);
			R[i][0]=1;
		}
		FOR(j,K) {
			(R[i-1][j]+=R[i][j])%=mo;;
			(R[i-1][(j+A[i-1])%K]+=R[i][j])%=mo;
		}
	}
	for(i=0;i+M<=ON;i++) {
		ll ret=mo-1;
		if(i%M==0) {
			FOR(j,K) ret+=1LL*L[i+1][j]*R[i+1][(K-j)%K]%mo;
		}
		else {
			FOR(j,K) ret+=1LL*R[i][j]*L[i+M][(K-j)%K]%mo;
		}
		cout<<ret%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

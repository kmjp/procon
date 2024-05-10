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
int A[202020],B[64],C[64];
const ll mo=1000000007;
ll p2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	if(N==2) {
		cout<<(A[0]+A[1])%mo<<endl;
		return;
	}
	int K=min(N,64);
	ll ret=0;
	FOR(i,N) {
		(ret+=A[0]*p2[N-1-i])%=mo;
		x=A[0];
		priority_queue<pair<int,int>> Q;
		FOR(j,K) {
			A[j]-=x;
		}
		FOR(j,K-1) {
			C[j]=j+1;
			Q.push({-(A[j]+A[j+1]),j});
		}
		FOR(j,K) {
			auto p=Q.top();
			Q.pop();
			B[j]=-p.first;
			x=p.second;
			C[x]++;
			if(C[x]<K) Q.push({-(A[x]+A[C[x]]),x});
		}
		FOR(j,K) A[j]=B[j];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

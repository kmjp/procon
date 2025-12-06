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
int A[202020];
int L[10101],R[10101];

ll from[10101];
ll S[10101];
ll to[10101];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) {
		L[i]=N,R[i]=-1;
		FOR(j,N) if(abs(A[i]-A[j])<=K) {
			L[i]=min(L[i],j);
			R[i]=max(R[i],j);
		}
		from[i]=1;
	}
	M--;
	while(M--) {
		FOR(i,N) S[i+1]=(S[i]+from[i])%mo;
		FOR(i,N) if(L[i]<=R[i]) to[i]=(S[R[i]+1]-S[L[i]]+mo)%mo;
		swap(from,to);
	}
	ll ret=0;
	FOR(i,N) ret+=from[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

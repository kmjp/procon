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
ll M,A[303030],B[303030];
int sum[1303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		sort(A,A+N);
		sort(B,B+N);
		
		ll ret=M-1;
		for(i=30;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			if(tmp<0) continue;
			FOR(j,4*N+3) sum[j]=0;
			FOR(j,N) {
				int num=lower_bound(B,B+N,tmp-A[j]+1)-B;
				int from=j+1,to=j+num;
				
				sum[from+2*N]++;
				sum[to+1+2*N]--;
				
				x=lower_bound(B,B+N,M-A[j])-B;
				y=lower_bound(B,B+N,M+tmp-A[j]+1)-B-1;
				// x-y‚àok
				k=N-1-j;
				
				sum[x-k+2*N]++;
				sum[y-k+1+2*N]--;
				
			}
			int ok=0;
			FOR(j,4*N+1) sum[j+1]+=sum[j];
			FOR(j,N) if(sum[j]+sum[j+N]+sum[j+N+N]+sum[j+N+N+N]==N) ret=tmp;
			
		}
		cout<<ret<<endl;
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

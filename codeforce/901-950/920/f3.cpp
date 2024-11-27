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

int T,N,Q;
ll A[202020];
ll X[202020][101];
ll Y[202020][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) cin>>A[i];
		for(i=1;i<=100;i++) {
			FOR(j,N) {
				X[j][i]=A[j]*j;
				Y[j][i]=A[j];
				if(j-i>=0) {
					X[j][i]+=X[j-i][i];
					Y[j][i]+=Y[j-i][i];
				}
			}
		}
		while(Q--) {
			int S,D,K;
			cin>>S>>D>>K;
			S--;
			ll ret=0;
			if(K<=1000) {
				FOR(i,K) ret+=A[S+i*D]*(i+1);
			}
			else {
				ret=X[S+(K-1)*D][D]-Y[S+(K-1)*D][D]*(S-D);
				if(S-D>=0) ret-=X[S-D][D]-Y[S-D][D]*(S-D);
				ret/=D;
			}
			cout<<ret<<" ";
			
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

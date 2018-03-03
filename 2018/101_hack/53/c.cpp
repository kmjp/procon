#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int D;
ll N,M,K;
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	while(D--) {
		cin>>N>>M>>K;
		ll ret=0;
		if(K==1) {
			// yoko
			ret+=M*(M-1)/2%mo*N%mo;
			//tate
			ret+=N*(N-1)/2%mo*M%mo;
			//naname
			for(int w=2;w<=min(N,M);w++) {
				ret+=(N+1-w)*(M+1-w)*2%mo;
			}
			ret=ret*2%mo;
		}
		else if(K==2) {
			for(int w=2;w<=min(N,M);w++) {
				ret+=(N+1-w)*(M+1-w)*4%mo;
				if(2*w-1<=N) ret+=(N+1-(2*w-1))*(M+1-w)*2%mo;
				if(2*w-1<=M) ret+=(M+1-(2*w-1))*(N+1-w)*2%mo;
			}
			ret=ret*6%mo;
		}
		else if(K==3) {
			for(int w=2;w<=min(N,M);w++) {
				ret+=(N+1-w)*(M+1-w)%mo;
				if(w%2==1) ret+=(N+1-w)*(M+1-w)%mo;
			}
			
			ret=ret*24%mo;
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

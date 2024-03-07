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

int N,Q;
ll A[202020],B[202020];
ll SA[202020],SB[202020];
ll miB[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) {
		miB[i]=B[i]=A[i]-i;
		if(i) miB[i]=min(miB[i],miB[i-1]);
		SA[i+1]=SA[i]+A[i];
		SB[i+1]=SB[i]+B[i];
	}
	while(Q--) {
		ll K;
		cin>>K;
		
		ll ret;
		
		if(N==1) {
			if(K%2==0) {
				ret=A[0]-K/2;
			}
			else {
				ret=A[0]+1+K/2;
			}
		}
		else if(K==N) {
			ret=miB[N-1]+N;
		}
		else if(K<N) {
			ret=min(miB[K-1]+K,A[K]);
		}
		else if(K%2==N%2) {
			ret=miB[N-1]+K;
			K-=N;
			assert(K%2==0);
			K/=2;
			K-=SB[N]-miB[N-1]*N;
			if(K>0) {
				ret-=K/N;
				if(K%N) ret--;
			}
		}
		else {
			ll a=miB[N-2]+K;
			ll b=A[N-1];
			K-=N-1;
			K/=2;
			K-=SB[N-1]-miB[N-2]*(N-1);
			if(a<b) {
				K-=b-a;
			}
			else if(a>b) {
				K-=(a-b)*(N-1);
				a=b;
			}
			ret=a;
			if(K>0) {
				ret-=K/N;
				if(K%N) ret--;
			}
			
		}
		cout<<ret<<" ";
	}
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

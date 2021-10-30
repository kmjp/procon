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
__int128 A[202020];
__int128 B[202020],C[202020],RC[202020];
__int128 SB[202020],SC[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A[i]=x;
	}
	
	__int128 mi=1LL<<62;
	
	
	FOR(j,4) {
		if(A[0]>=0) {
			B[0]=A[0];
			C[0]=0;
			RC[0]=0;
		}
		else {
			B[0]=0;
			C[0]=A[0];
			RC[0]=-A[0];
		}
		SB[1]=B[0];
		SC[1]=RC[0];
		
		for(i=1;i<N;i++) {
			if(A[i]>=A[i-1]) {
				B[i]=B[i-1]+(A[i]-A[i-1]);
				C[i]=C[i-1];
			}
			else {
				B[i]=B[i-1];
				C[i]=C[i-1]+(A[i]-A[i-1]);
			}
			RC[i]=-C[i];
			SB[i+1]=SB[i]+B[i];
			SC[i+1]=SC[i]+RC[i];
		}
		
		
		FOR(i,N) {
			__int128 dif=B[i];
			
			__int128 add=(__int128)(SB[N]-SB[i])-(__int128)dif*(N-i);
			add+=dif*i-SB[i];
			
			dif=A[i]-C[i];
			x=lower_bound(RC,RC+N,dif)-RC;
			add+=(__int128)(SC[N]-SC[x])-(__int128)dif*(N-x);
			add+=(__int128)dif*x-SC[x];
			
			mi=min(mi,add);
		}
		
		if(j==0||j==2) {
			FOR(i,N) A[i]=-A[i];
		}
		if(j==1) {
			reverse(A,A+N);
		}
		
	}
	
	
	cout<<(ll)mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

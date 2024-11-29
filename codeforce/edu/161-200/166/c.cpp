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

int T,N,M;
int A[202020],B[202020];
int AS[202020],BS[202020];
ll sum[202020],sum2[202020];;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+M+1) cin>>A[i];
		FOR(i,N+M+1) cin>>B[i];
		FOR(i,N+M+1) {
			AS[i+1]=AS[i]+(A[i]>B[i]);
			BS[i+1]=BS[i]+(A[i]<B[i]);
			sum[i]=sum2[i]=0;
		}
		FOR(i,N+M+1) {
			if(A[i]>B[i]) {
				if(AS[i]<N) {
					sum[0]+=A[i];
					sum[i]-=A[i];
					sum[i+1]+=A[i];
				}
				else if(AS[i]==N) {
					FOR(j,i) {
						if(A[j]>B[j]) sum2[j]+=A[i];
						else sum2[j]+=B[i];
					}
					sum[i+1]+=B[i];
				}
				else {
					sum[0]+=B[i];
					sum[i]-=B[i];
					sum[i+1]+=B[i];
					
				}
			}
			else {
				if(BS[i]<M) {
					sum[0]+=B[i];
					sum[i]-=B[i];
					sum[i+1]+=B[i];
				}
				else if(BS[i]==M) {
					FOR(j,i) {
						if(A[j]<B[j]) sum2[j]+=B[i];
						else sum2[j]+=A[i];
					}
					sum[i+1]+=A[i];
				}
				else {
					sum[0]+=A[i];
					sum[i]-=A[i];
					sum[i+1]+=A[i];
					
				}
			}
		}
		FOR(i,N+M+1) {
			if(i) sum[i]+=sum[i-1];
			cout<<sum[i]+sum2[i]<<" ";
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

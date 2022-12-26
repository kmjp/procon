#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int A[1010101];
ll sum[1010101];
int phi[1010101];
int di[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	for(i=1;i<=1000000;i++) phi[i]=i;
	for(i=2;i<=1000000;i++) if(di[i]==0) {
		for(j=i;j<=1000000;j+=i) di[j]=i, phi[j]=phi[j]/i*(i-1);
	}
	
	sum[1]=1;
	for(i=2;i<=1000000;i++) {
		for(j=1;j*j<=i;j++) if(i%j==0) {
			sum[i]+=(ll)j*phi[i/j];
			if(j*j!=i) sum[i]+=(ll)(i/j)*phi[j];
		}
	}
	
	ll ret=0;
	FOR(i,M) {
		cin>>x;
		ret+=sum[x]-x;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

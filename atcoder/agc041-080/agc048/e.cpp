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

int N,K;
ll T;
ll B[52][52];
const ll mo=1000000007;
ll from[52],to[52];
ll p[54];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>T;
	FOR(i,N) FOR(x,K) cin>>B[i][x];
	
	p[0]=1;
	FOR(i,51) p[i+1]=p[i]*K%mo;
	
	cout<<0<<endl;
	for(i=1;i<N;i++) {
		ll ret=0;
		FOR(x,K) {
			ZERO(from);
			from[0]=1;
			for(j=i-1;j>=0;j--) {
				ZERO(to);
				FOR(k,K) FOR(y,N+1) {
					if(B[j][k]<B[i][x]+T*(y+1)) (to[y+1]+=from[y])%=mo;
					else (to[y]+=from[y])%=mo;
				}
				swap(from,to);
			}
			FOR(y,N+1) (ret+=y*from[y]%mo*p[N-1-i])%=mo;
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

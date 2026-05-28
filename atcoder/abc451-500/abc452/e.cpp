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

int N,M;
ll A[2505050];
ll SA[2505050];
ll SA2[2505050];
ll B;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,2*(N+M)) {
		if(i<N) cin>>A[i+1];
		SA[i+1]=(SA[i]+A[i+1])%mo;
		SA2[i+1]=(SA2[i]+A[i+1]*(i+1))%mo;
	}
	
	ll ret=0;
	for(i=1;i<=M;i++) {
		cin>>B;
		ll sum=0;
		for(j=0;j*i<=N;j++) {
			sum+=SA2[(j+1)*i-1];
			if(j) sum-=SA2[j*i-1];
			sum-=SA[(j+1)*i-1]*j%mo*i%mo;
			if(j) sum+=SA[j*i-1]*j%mo*i%mo;
		}
		ret+=sum*B%mo;
		
	}
	ret=(ret%mo+mo)%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

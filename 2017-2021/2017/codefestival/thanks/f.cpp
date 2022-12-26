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

int N,K;
int A[101010];
ll from[1<<17],to[1<<17];
int mo=1000000007;
int cnt[101010];
ll p2[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		cnt[A[i]]++;
	}
	
	p2[0]=1;
	FOR(i,101000) p2[i+1]=p2[i]*2%mo;
	
	int tot=0;
	from[0]=1;
	FOR(i,101010) if(cnt[i]) {
		ZERO(to);
		
		FOR(j,1<<17) {
			(to[j]+=p2[cnt[i]-1]*from[j])%=mo;
			(to[i^j]+=p2[cnt[i]-1]*from[j])%=mo;
		}
		
		swap(from,to);
	}
	cout<<from[K]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N;
int C[1<<17];
int S[1<<17];
int P[1<<17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C[x]++;
		S[x]++;
	}
	
	for(i=16;i>=0;i--) {
		FOR(j,1<<17) if((j&(1<<i))==0) S[j] += S[j|(1<<i)];
	}
	FOR(j,1<<17) if(S[j]) P[j]=j;
	for(i=16;i>=0;i--) {
		FOR(j,1<<17) if((j&(1<<i))) P[j] = max(P[j],P[j^(1<<i)]);
	}
	
	int ma=0;
	FOR(i,1<<17) if(S[i]) ma=max(ma,i | P[i^((1<<17)-1)]);
	
	ll cnt=0;
	FOR(i,1<<17) if(C[i]) {
		if(i==ma) {
			cnt += 1LL*C[i]*(N-1);
		}
		else if((i|P[i^((1<<17)-1)])==ma) {
			cnt += 1LL*C[i]*S[P[i^((1<<17)-1)]];
		}
	}
	cout<<ma<<" "<<cnt/2<<" "<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

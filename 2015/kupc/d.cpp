#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[101010],B[101010];
ll SB[101010];
ll md[101010],mn[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) {
		cin>>B[i+1];
		SB[i+1]=max(SB[i],B[i+1]);
	}
	
	ll ma=0;
	for(i=1;i<=N+1;i++) {
		if(i>1) {
			if(mn[i-1]+A[i-1]>=0) {
				md[i]=md[i-1]+1;
				mn[i]=mn[i-1]+A[i-1];
			}
			else if(SB[i-1]==0) {
				break;
			}
			else {
				ll f=-(mn[i-1]+A[i-1]);
				ll ad = (f+SB[i-1]-1)/SB[i-1];
				
				md[i]=md[i-1]+1+ad;
				mn[i]=mn[i-1]+A[i-1]+ad*SB[i-1];
			}
		}
		if(md[i]<=N) ma=max(ma, mn[i] + (N-md[i])*SB[i]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

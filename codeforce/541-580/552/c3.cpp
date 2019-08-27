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

ll A[3];
int B[7]={0,1,2,0,2,1,0};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	ll c=min({A[0]/3,A[1]/2,A[2]/2});
	
	A[0]-=3*c;
	A[1]-=2*c;
	A[2]-=2*c;
	
	ll ret=0;
	FOR(i,7) {
		ll C[3]={A[0],A[1],A[2]};
		for(j=0;;j++) {
			if(C[B[(i+j)%7]]==0) break;
			C[B[(i+j)%7]]--;
		}
		ret=max(ret,(ll)j);
	}
	cout<<7*c+ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

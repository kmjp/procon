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

int T;
ll A,B,C,X,Y,Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>X>>Y>>Z;
		
		ll mi=1LL<<60;
		
		// B->C->A
		{
			ll TA=0;
			ll TC=max(A+1,C)-C;
			ll TB=max(C+TC+1,B)-B;
			if(A-TC-TB>0 && B-TA-TC>0 && C-TA-TB>0) mi=min(mi,TA*Y+TB*Z+TC*X);
		}
		// B->A->C
		{
			ll TC=0;
			ll TA=max(C+1,A)-A;
			ll TB=max(A+TA+1,B)-B;
			if(A-TC-TB>0 && B-TA-TC>0 && C-TA-TB>0) mi=min(mi,TA*Y+TB*Z+TC*X);
		}
		// C->A->B
		{
			ll TB=0;
			ll TA=max(B+1,A)-A;
			ll TC=max(A+TA+1,C)-C;
			if(A-TC-TB>0 && B-TA-TC>0 && C-TA-TB>0) mi=min(mi,TA*Y+TB*Z+TC*X);
		}
		// A->C->B
		{
			ll TB=0;
			ll TC=max(B+1,C)-C;
			ll TA=max(C+TC+1,A)-A;
			if(A-TC-TB>0 && B-TA-TC>0 && C-TA-TB>0) mi=min(mi,TA*Y+TB*Z+TC*X);
		}
		
		
		if(mi==1LL<<60) mi=-1;
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

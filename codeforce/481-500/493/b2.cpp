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


int N,B;
int A[101];
int C[101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) C[i+1]=-200;
	
	int ma=0;
	FOR(i,N) {
		ma=max(ma,C[i]);
		x=0;
		for(j=i;j<N;j++) {
			if(A[j]&1) x++;
			else x--;
			if(x==0 && abs(A[j]-A[j+1])<=B) C[j+1]=max(C[j+1],C[i]+1);
		}
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

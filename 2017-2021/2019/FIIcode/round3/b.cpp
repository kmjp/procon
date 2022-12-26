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
string A[101010],B[101010];
int ma[2][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	for(i=N-1;i>=0;i--) {
		int maa=1,mab=1;
		FORR(c,A[i]) maa=max(maa,ma[1][c-'0']+1);
		FORR(c,B[i]) mab=max(mab,ma[0][c-'0']+1);
		FORR(c,A[i]) ma[0][c-'0']=max(ma[0][c-'0'],maa);
		FORR(c,B[i]) ma[1][c-'0']=max(ma[1][c-'0'],mab);
	}
	
	cout<<*max_element(ma[0],ma[0]+10)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int A[10];
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) cin>>A[i];
	cin>>N;
	
	N-=min(N/500,A[0])*500;
	N-=min(N/100,A[1])*100;
	N-=min(N/50,A[2])*50;
	N-=min(N/10,A[3])*10;
	N-=min(N/5,A[4])*5;
	N-=min(N/1,A[5])*1;
	
	if(N==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

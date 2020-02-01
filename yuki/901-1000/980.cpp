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
ll P;
ll mo=1000000007;
ll A[2020202];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	A[2]=1;
	A[3]=2*P%mo;
	for(i=4;i<=2020101;i++) {
		A[i]=2*P*A[i-1]%mo+(2-P*P%mo)*A[i-2]%mo-2*P%mo*A[i-3]%mo-A[i-4];
		A[i]=(A[i]%mo+mo)%mo;
	}
	
	
	cin>>Q;
	while(Q--) {
		cin>>x;
		cout<<A[x-2]<<endl;
	}
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

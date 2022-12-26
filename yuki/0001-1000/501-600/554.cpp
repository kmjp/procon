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
ll mo=1000000007;

ll A[101010];
ll S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A[1]=S[1]=1;
	for(i=2;i<=N;i++) {
		if(i%2==0) {
			A[i]=i*S[1]%mo;
			(S[0]+=A[i])%=mo;
		}
		else {
			A[i]=i*S[0]%mo;
			(S[1]+=A[i])%=mo;
		}
	}
	cout<<A[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

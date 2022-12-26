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


ll N;
const ll mo=998244353;

ll S[5];
ll A[202020];
ll B[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	S[1]=1;
	for(i=1;i<=N;i++) S[1]=S[1]*i%mo;
	A[0]=B[0]=1;
	for(i=2;i<=N;i++) {
		A[i]=(i-1)*(A[i-1]+A[i-2])%mo;
		if(i>=4) {
			if(i%2==0) B[i]=((i-1)*B[i-1]+2*(i-2)*B[i-4])%mo;
			else B[i]=((i-1)*B[i-1]+2*(i-1)*B[i-2])%mo;
		}
	}
	S[2]=S[3]=A[N];
	S[4]=B[N];
	
	ll ret=S[1]-S[2]-S[3]+S[4]+mo+mo;
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
ll mo=1000000007;
ll F[1010101];
ll S[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	F[1]=S[1]=N;
	F[2]=N*N%mo;
	S[2]=(S[1]+F[2])%mo;
	for(i=3;i<=N;i++) {
		F[i]=F[i-1];
		F[i]+=(N-1)*(N-1);
		F[i]+=S[i-3]+(N-1-(i-3));
		F[i]%=mo;
		S[i]=(S[i-1]+F[i])%mo;
	}
	
	cout<<F[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

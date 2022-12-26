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

int M,N,K;
int C[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N>>K;
	FOR(i,N) {
		cin>>x;
		C[x]++;
	}
	
	int ma=0;
	for(i=1;i<=M;i++) {
		x=C[i];
		for(j=1;j<=K;j++) {
			x+=max(min((i-j>=0)?C[i-j]:0,1),min((i+j<=M)?C[i+j]:0,1));
		}
		ma=max(ma,x);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

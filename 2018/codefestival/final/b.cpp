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

int N,M;
int R[101010];

double fl[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=101000;i++) fl[i]=fl[i-1]+log(i);
	
	cin>>N>>M;
	double ret=0;
	FOR(i,M-1) {
		cin>>R[i];
		
		ret+=log(M-i-1)*(N-R[i])-log(M-i)*N;
		if(R[i]!=N && R[i]!=0) ret+=fl[N]-fl[R[i]]-fl[N-R[i]];
		N-=R[i];
	}
	ret/=log(10);
	cout<<-floor(ret)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

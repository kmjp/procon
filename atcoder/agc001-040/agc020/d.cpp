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

int Q;
int A,B,C,D;

string hoge(int A,int B,int C,int D) {
	int i;
	int L=(max(A,B)+min(A,B))/(min(A,B)+1);
	
	int na=0;
	for(i=30;i>=0;i--) {
		int nac=na+(1<<i);
		int nb=max(0,(nac-1)/L);
		if(nac>A || nb>B) continue;
		int ma=A-nac;
		int mb=B-nb;
		
		if(mb>1LL*(ma+1)*L) continue;
		na+=1<<i;
	}
	
	
	int p=na+max(0,(na-1)/L);
	string R;
	for(i=C;i<=D;i++) {
		if(i<p) R+='A'+(i%(L+1)==L);
		else R+='B'-((A+B-1-i)%(L+1)==L);
	}
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>A>>B>>C>>D;
		cout<<hoge(A,B,C-1,D-1)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

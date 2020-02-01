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
int P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ret=0;
	FOR(i,N) {
		cin>>x;
		int ma=1;
		for(j=1;j*j<=x;j++) if(x%j==0) {
			if(x!=1) ma=max(ma,P[j]+1);
			if(j>1) ma=max(ma,P[x/j]+1);
		}
		P[x]=max(P[x],ma);
		ret=max(ret,ma);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

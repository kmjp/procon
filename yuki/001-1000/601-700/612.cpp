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

int T;
int A,B,C,D,E;
ll from[20202];
ll to[20202];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>A>>B>>C>>D>>E;
	int ma=max({abs(A),abs(B),abs(C)});
	from[10100]=1;
	FOR(i,T) {
		ZERO(to);
		for(j=10100-ma*i;j<=10100+ma*i;j++) if(from[j]) {
			from[j]%=mo;
			to[j-A]+=from[j];
			to[j+A]+=from[j];
			to[j-B]+=from[j];
			to[j+B]+=from[j];
			to[j-C]+=from[j];
			to[j+C]+=from[j];
		}
		swap(from,to);
	}
	
	ll ret=0;
	for(i=10100+D;i<=10100+E;i++) ret+=from[i];
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

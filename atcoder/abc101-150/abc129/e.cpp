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


string L;
int N;
ll mo=1000000007;
ll S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L;
	L="0"+L;
	N=L.size();
	ll ret=0;
	ll v=1,a=1;
	
	int c=1;
	S[0]=1;
	FOR(i,N) {
		S[i+1]=S[i];
		if(L[i]=='1') S[i+1]=S[i+1]*2%mo;
	}
	
	for(i=N-1;i>=1;i--) {
		if(L[i]=='1') {
			v=v*2%mo;
			ret+=a*S[i]%mo;
		}
		a=a*3%mo;
	}
	ret+=v;
	cout<<(ret%mo)<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

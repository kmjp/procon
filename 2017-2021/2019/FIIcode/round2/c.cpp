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

ll N,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	
	if(N>=X) {
		cout<<X-1<<endl;
		return;
	}
	
	ll ma=0;
	for(i=1;i<N;i++) {
		ll F=X-(N-i);
		ll sum=1LL*i*(i-1)/2+(F+F+N-i-1)*(N-i)/2;
		if(sum==Y) {
			cout<<X-1<<endl;
			return;
		}
	}
	
	ll TY=Y-1LL*N*(N-1)/2;
	ll P=TY/N;
	cout<<P+N-1<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

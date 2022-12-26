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

int A,B,M;
int AA[101010];
int BB[101010];




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>M;
	FOR(i,A) cin>>AA[i];
	FOR(i,B) cin>>BB[i];
	
	ll ret=*min_element(AA,AA+A)+*min_element(BB,BB+B);
	FOR(i,M) {
		cin>>x>>y>>r;
		ll tmp=AA[x-1]+BB[y-1]-r;
		ret=min(ret,tmp);
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

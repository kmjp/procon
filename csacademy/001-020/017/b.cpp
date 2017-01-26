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


int N,A,B;
int X[101010];
int Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,A) cin>>X[i];
	sort(X,X+A);
	Y[0]=-1<<30;
	FOR(i,B) cin>>Y[i+1];
	Y[B+1]=1<<30;
	sort(Y,Y+B+2);
	
	ll tot=0;
	x=0;
	FOR(i,A) {
		while(Y[x+1]<X[i]) x++;
		tot+=min(X[i]-Y[x],Y[x+1]-X[i]);
	}
	cout<<tot<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

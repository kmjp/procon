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

ll A,B;
ll X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	X=Y=1;
	while(A && A%10==0) A/=10, X*=10;
	while(B && B%10==0) B/=10, Y*=10;
	
	if(X>=100 && Y>=100 && abs(A)<10 && abs(B)<10) {
		cout<<A*B*X*Y/10<<endl;
	}
	else {
		A*=B*X*Y;
		if(A<-99999999 || A>99999999) cout<<"E"<<endl;
		else cout<<A<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

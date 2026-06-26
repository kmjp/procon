#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
ll A,B,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>X>>Y;
		X=abs(X);
		Y=abs(Y);
		
		ll ret=2*min(A,B)*min(X,Y);
		ll a=min(X,Y);
		X-=a;
		Y-=a;
		if(X>0) {
			ll p1=(X+1)/2*A+X/2*B;
			ll p2=X/2*(4*min(A,B))+((X%2)?min(A,3*B):0);
			ret+=min(p1,p2);
		}
		else {
			ll p1=(Y+1)/2*B+Y/2*A;
			ll p2=Y/2*(4*min(A,B))+((Y%2)?min(B,3*A):0);
			ret+=min(p1,p2);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

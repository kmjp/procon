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
ll X1,Y1,X2,Y2;
ll p3[32];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,31) p3[i+1]=p3[i]*3;
	
	cin>>Q;
	while(Q--) {
		cin>>X1>>Y1>>X2>>Y2;
		X1--;
		Y1--;
		X2--;
		Y2--;
		
		ll ret=abs(X1-X2)+abs(Y1-Y2);
		for(i=29;i>=0;i--) {
			ll x1=X1/p3[i];
			ll y1=Y1/p3[i];
			ll x2=X2/p3[i];
			ll y2=Y2/p3[i];
			if(x1==x2 && x1%3==1 && abs(y1-y2)>=2) {
				ret=abs(Y2-Y1)+min(X1%p3[i]+X2%p3[i]+2,2*p3[i]-X1%p3[i]-X2%p3[i]);
				break;
			}
			if(y1==y2 && y1%3==1 && abs(x1-x2)>=2) {
				ret=abs(X2-X1)+min(Y1%p3[i]+Y2%p3[i]+2,2*p3[i]-Y1%p3[i]-Y2%p3[i]);
				break;
			}
			
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

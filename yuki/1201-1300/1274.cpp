#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A>>B;
	A=abs(A);
	B=abs(B);
	if(A>B) swap(A,B);
	
	if(B==0) {
		cout<<0.25<<endl;
		return;
	}
	double ret=0;
	ll g=__gcd(A,B);
	int par=(A/g+B/g)%2;
	for(ll x=1;x<=1000;x+=g) {
		for(ll y=1;y<=1000;y+=g) {
			if(par==0 && ((x-1)/g+(y-1)/g)%2==1) continue;
			ret+=1.0/pow(x+y,x+y);
		}
	}
	
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

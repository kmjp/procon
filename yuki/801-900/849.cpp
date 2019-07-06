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
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll x1,y1,x2,y2;
	
	cin>>x1>>y1>>x2>>y2;
	
	if(x1==0 && x2==0) y1=__gcd(y1,y2);
	else if(y1==0 && y2==0) x1=__gcd(x1,x2);
	else {
		if(x2<x1) swap(x1,x2),swap(y1,y2);
		while(x1&&x2) {
			ll d=x2/x1;
			x2=x2-x1*d;
			y2=y2-y1*d;
			if(x2<x1) swap(x1,x2),swap(y1,y2);
		}
		if(x2<x1) swap(x1,x2),swap(y1,y2);
		
	}
	set<pair<ll,ll>> S;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(x1==0 && x2==0) Y[i]%=y1;
		else if(y1==0 && y2==0) X[i]%=x1;
		else {
			ll d=X[i]/x2;
			X[i]-=x2*d;
			Y[i]-=y2*d;
			if(y1) Y[i]=(Y[i]%y1+y1)%y1;
		}
		
		S.insert({X[i],Y[i]});
	}
	
	
	cout<<S.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

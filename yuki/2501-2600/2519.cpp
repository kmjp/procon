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

ll F(ll a,ll b) {
	if(__gcd(a,b)==1) return (a-1)*(b-1);
	return 0;
}

int N;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(N!=3) {
		for(i=1;i<N;i++) {
			A[0]=F(A[0],A[i]);
		}
		if(N>=4) cout<<0<<endl;
		else cout<<A[0]<<endl;
		FOR(i,N-1) cout<<"1 2"<<endl;
	}
	else {
		ll a=F(F(A[0],A[1]),A[2]);
		ll b=F(F(A[0],A[2]),A[1]);
		ll c=F(F(A[1],A[2]),A[0]);
		if(a<=b&&a<=c) {
			cout<<a<<endl;
			cout<<"1 2"<<endl;
		}
		else if(b<=a&&b<=c) {
			cout<<b<<endl;
			cout<<"1 3"<<endl;
		}
		else {
			cout<<c<<endl;
			cout<<"2 3"<<endl;
		}
		cout<<"1 2"<<endl;
			
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

ll A,B,C,D,P,R,Q,S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D>>P>>Q>>R>>S>>T;
	
	FOR(i,4) {
		if(P>Q) swap(P,Q),swap(A,B);
		if(Q>R) swap(Q,R),swap(B,C);
		if(R>S) swap(R,S),swap(C,D);
	}
	
	ll ret=0;
	{
		ll a=min(A,T/P);
		ret+=a;
		T-=a*P;
	}
	{
		ll a=min(B,T/Q);
		ret+=a;
		T-=a*Q;
	}
	{
		ll a=min(C,T/R);
		ret+=a;
		T-=a*R;
	}
	{
		ll a=min(D,T/S);
		ret+=a;
		T-=a*S;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

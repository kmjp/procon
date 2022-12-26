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

ll N,A,B,X,Y;
ll V[103030];



int can(int v) {
	ll H[103030];
	ll sum=0;
	int i;
	ll A=::A,B=::B;
	FOR(i,N) {
		H[i]=max(0LL,V[i]-v);
		ll a=min(A,H[i]/X);
		H[i]-=a*X;
		A-=a;
	}
	sort(H,H+N);
	for(i=N-1;i>=0;i--) if(H[i]) {
		if(A) {
			H[i]=0;
			A--;
		}
		else sum+=H[i];
	}
	return (sum<=1LL*B*Y);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>A>>B>>X>>Y;
	FOR(i,N) cin>>V[i];
	
	int ok=(1<<30)-1;
	for(i=29;i>=0;i--) if(can(ok-(1<<i))) ok-=1<<i;
	cout<<ok<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

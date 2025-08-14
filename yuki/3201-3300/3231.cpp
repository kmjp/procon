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

const ll mo=1000000007;
ll A[2][2],B[2][2];

void yes() {
	cout<<"Yes"<<endl;
	exit(0);
}
void no() {
	cout<<"No"<<endl;
	exit(0);
}
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,2) FOR(x,2) cin>>A[y][x];
	FOR(y,2) FOR(x,2) cin>>B[y][x];
	
	FOR(i,4) if(A[i%2][i/2]!=B[i%2][i/2]) break;
	if(i==4) yes();
	if(A[0][0]==A[1][1]&&A[0][1]==0&&A[1][0]==0) no();
	if(B[0][0]==B[1][1]&&B[0][1]==0&&B[1][0]==0) no();
	
	ll ax=((-A[0][0]-A[1][1])%mo+mo)%mo;
	ll bx=((-B[0][0]-B[1][1])%mo+mo)%mo;
	ll a=((A[0][0]*A[1][1]-A[0][1]*A[1][0])%mo+mo)%mo;
	ll b=((B[0][0]*B[1][1]-B[0][1]*B[1][0])%mo+mo)%mo;
	if(ax==bx&&a==b) yes();
	no();
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
ll A,N;
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>N;
		
		ll P=A*A;
		ll Q=-2*A*(A-1)/2;
		ll R=0;
		FOR(i,A) {
			R+=1LL*i*i/A-(1LL*i*i%A==0);
		}
		ll M=N/A;
		__int128 r=sqrt(A*N);
		while(r*r>A*N) r--;
		while((r+1)*(r+1)<=A*N) r++;
		__int128 tot=r*N;
		
		ll v=r/A;
		tot-=(__int128)P*v*(v+1)*(2*v+1)/6;
		tot-=(__int128)Q*v*(v+1)/2;
		tot-=(__int128)R*v;
		for(__int128 b=v*A+1;b<=r;b++) tot-=b*b/A-(b*b%A==0);
		tot%=mo;
		cout<<(ll)tot<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

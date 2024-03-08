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

int T,N;
ll A[55];

ll issq(ll V) {
	ll a=sqrt(V);
	if(a*a==V) return 1;
	if((a-1)*(a-1)==V) return 1;
	if((a+1)*(a+1)==V) return 1;
	return 0;
}

int check(ll a) {
	int ok=0;
	int i;
	FOR(i,N) if(issq(A[i]+a)) ok++;
	return ok;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		int L=0;
		
		FOR(i,N) {
			cin>>A[i];
		}
		int ret=1;
		FOR(y,N) FOR(x,y) {
			ll d=A[y]-A[x];
			for(i=1;i*i<=d;i++) if(d%i==0) {
				j=d/i;
				if(j%2!=i%2) continue;
				ll b=(j+i)/2;
				ll c=(j-i)/2;
				if(b*b>=A[y]&&c*c>=A[x]) ret=max(ret,check(b*b-A[y]));
				
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

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
ll A[202020];

ll sum() {
	int i;
	ll s=0;
	FOR(i,N-1) s+=(A[i]+A[i+1])/2;
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> V[2];
		FOR(i,N) {
			cin>>x;
			V[x%2].push_back(x);
		}
		sort(ALL(V[0]));
		sort(ALL(V[1]));
		reverse(ALL(V[0]));
		reverse(ALL(V[1]));
		ll ret=1LL<<60;
		if(V[0].size()>=2) {
			A[0]=V[0][0];
			A[N-1]=V[0][1];
			x=2;
			y=0;
			for(i=1;i<=N-2;i++) {
				if(A[i-1]%2==0) {
					if(y<V[1].size()) A[i]=V[1][y++];
					else A[i]=V[0][x++];
				}
				else {
					if(x<V[0].size()) A[i]=V[0][x++];
					else A[i]=V[1][y++];
				}
				
			}
			ret=min(ret,sum());
		}
		if(V[0].size()&&V[1].size()) {
			A[0]=V[0][0];
			A[N-1]=V[1][0];
			x=1;
			y=1;
			for(i=1;i<=N-2;i++) {
				if(A[i-1]%2==0) {
					if(y<V[1].size()) A[i]=V[1][y++];
					else A[i]=V[0][x++];
				}
				else {
					if(x<V[0].size()) A[i]=V[0][x++];
					else A[i]=V[1][y++];
				}
				
			}
			ret=min(ret,sum());
		}
		if(V[1].size()>=2) {
			A[0]=V[1][0];
			A[N-1]=V[1][1];
			x=0;
			y=2;
			for(i=1;i<=N-2;i++) {
				if(A[i-1]%2==0) {
					if(y<V[1].size()) A[i]=V[1][y++];
					else A[i]=V[0][x++];
				}
				else {
					if(x<V[0].size()) A[i]=V[0][x++];
					else A[i]=V[1][y++];
				}
				
			}
			ret=min(ret,sum());
			
			
			
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

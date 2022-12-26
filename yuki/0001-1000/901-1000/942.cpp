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

ll N,K;

vector<ll> R[202020];

void ok() {
	int i;
	cout<<"Yes"<<endl;
	FOR(i,K) {
		FORR(c,R[i]) cout<<c<<" ";
		cout<<endl;
	}
	exit(0);
	return;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll sum=N*(N+1)/2;
	if(sum%K) return _P("No\n");
	if(K==N && K!=1) return _P("No\n");
	
	int P=N/K;
	
	if(P%2==0 || P==1) {
		FOR(x,P) {
			FOR(y,K) {
				if(x%2==0) R[y].push_back(x*K+y+1);
				else R[K-1-y].push_back(x*K+y+1);
			}
		}
		ok();
	}
	if(P>=3) {
		ll X=3*K*(3*K+1)/2/K;
		
		FOR(y,K) R[y].push_back(3*K-y);
		FOR(y,K) {
			if(y<=K/2) R[y].push_back(1+y*2);
			else R[y].push_back((y-K/2)*2);
			R[y].push_back(X-R[y][0]-R[y][1]);
		}
		
		for(x=3;x<P;x++) {
			FOR(y,K) {
				if(x%2==0) R[y].push_back(x*K+y+1);
				else R[K-1-y].push_back(x*K+y+1);
			}
		}
		ok();
	}
	
	
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

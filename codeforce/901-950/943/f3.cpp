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

int T,N,Q;
int A[202020];
int S[202020];
map<int,set<int>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		V.clear();
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=A[i]^S[i];
		}
		FOR(i,N+1) V[S[i]].insert(i);
		
		while(Q--) {
			int L,R;
			cin>>L>>R;
			L--;
			if(S[L]==S[R]) {
				cout<<"YES"<<endl;
				continue;
			}
			x=*V[S[R]].lower_bound(L);
			if(x>=R) {
				cout<<"NO"<<endl;
				continue;
			}
			auto it=V[S[L]].lower_bound(x);
			if(it==V[S[L]].end()||*it>R) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
			}
				
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

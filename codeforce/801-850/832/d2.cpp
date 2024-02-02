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


int N,Q;
ll A[202020];
ll S[202020],T[202020];
int C[202020][30];

map<ll,set<int>> memo[2];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]^A[i];
		T[i+1]=T[i]+A[i];
	}
	FOR(i,N+1) memo[i%2][S[i]].insert(i);
	
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		
		if(T[R]==T[L]) {
			cout<<0<<endl;
		}
		else if(S[R]!=S[L]) {
			cout<<-1<<endl;
		}
		else if((R-L)%2==1||A[L]==0||A[R-1]==0) {
			cout<<1<<endl;
		}
		else {
			auto it=memo[(L%2)^1][S[L]].lower_bound(L);
			if(it!=memo[(L%2)^1][S[L]].end()&&*it<=R) {
				cout<<2<<endl;
				continue;
			}
			it=memo[(R%2)^1][S[R]].lower_bound(R);
			if(it!=memo[(R%2)^1][S[R]].begin()&&*--it>=L) {
				cout<<2<<endl;
				continue;
			}
			cout<<-1<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

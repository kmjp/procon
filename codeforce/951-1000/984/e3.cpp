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

int H,W,Q;
vector<ll> A[101010];
int M;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(x,W) A[x].push_back(0);
	FOR(y,H) {
		FOR(x,W) {
			cin>>k;
			A[x].push_back(A[x].back()|k);
		}
	}
	while(Q--) {
		int L=1,R=H;
		cin>>M;
		while(M--) {
			cin>>x>>s>>y;
			x--;
			if(s=="<") {
				k=lower_bound(ALL(A[x]),y)-A[x].begin();
				R=min(R,k-1);
			}
			else {
				k=lower_bound(ALL(A[x]),y+1)-A[x].begin();
				L=max(L,k);
			}
		}
		if(L<=R) cout<<L<<endl;
		else cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

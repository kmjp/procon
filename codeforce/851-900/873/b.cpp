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

int T,N,A[303030];

int L[303030],R[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i];
			V.push_back({A[i],i});
		}
		ll sum=0;
		for(i=1;i<=N;i++) sum+=1LL*(i-1)*(N+1-i);
		sort(ALL(V));
		set<int> L={-1,N},M={-1,N};
		FOR(i,N) M.insert(i);
		
		FORR2(a,b,V) {
			M.erase(b);
			int k=*prev(L.lower_bound(b));
			int x=*prev(M.lower_bound(k+1));
			int y=*L.lower_bound(b);
			sum-=1LL*(k-x)*(y-b);
			
			L.insert(b);
		}
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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


int N;
vector<ll> A[3];
string C[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		ll B;
		cin>>B>>s;
		if(s=="R") A[0].push_back(B);
		if(s=="G") A[1].push_back(B);
		if(s=="B") A[2].push_back(B);
	}
	sort(ALL(A[0]));
	sort(ALL(A[1]));
	sort(ALL(A[2]));
	
	if(A[0].size()%2) {
		if(A[1].size()%2==0) swap(A[0],A[1]);
		else swap(A[0],A[2]);
	}
	if(A[1].size()%2==0) {
		cout<<0<<endl;
		return;
	}
	ll mi=1LL<<60;
	FORR(a,A[1]) {
		x=lower_bound(ALL(A[2]),a+1)-A[2].begin();
		if(x<A[2].size()) mi=min(mi,abs(A[2][x]-a));
		x--;
		if(x>=0) mi=min(mi,abs(A[2][x]-a));
	}
	ll mia=1LL<<60,mib=1LL<<60;
	FORR(a,A[1]) {
		x=lower_bound(ALL(A[0]),a+1)-A[0].begin();
		if(x<A[0].size()) mia=min(mia,abs(A[0][x]-a));
		x--;
		if(x>=0) mia=min(mia,abs(A[0][x]-a));
	}
	FORR(a,A[2]) {
		x=lower_bound(ALL(A[0]),a+1)-A[0].begin();
		if(x<A[0].size()) mib=min(mib,abs(A[0][x]-a));
		x--;
		if(x>=0) mib=min(mib,abs(A[0][x]-a));
	}
	
	
	cout<<min(mi,mia+mib)<<endl;
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

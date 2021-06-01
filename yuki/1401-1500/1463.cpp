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

int N,K,A[18];
vector<int> V[18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		x=A[i];
		for(j=2;j<=1000;j++) while(x%j==0) x/=j, V[i].push_back(j);
	}
	set<ll> S;
	set<vector<int>> C;
	int mask;
	FOR(mask,1<<N) if(__builtin_popcount(mask)>=K) {
		int sum=0;
		ll mul=1;
		vector<int> P;
		FOR(i,N) if(mask&(1<<i)) {
			sum+=A[i];
			mul*=A[i];
			if(mul>100000) mul=100000;
			FORR(v,V[i]) P.push_back(v);
		}
		
		S.insert(sum);
		
		if(mul<100000){
			S.insert(mul);
		} 
		else {
			sort(ALL(P));
			C.insert(P);
		}
	}
	cout<<S.size()+C.size()<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

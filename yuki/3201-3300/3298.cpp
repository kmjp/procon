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

int N,K,Q;
multiset<ll> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) {
		cin>>x;
		B.insert(x);
	}
	FOR(i,K) {
		A.insert(*B.begin());
		B.erase(B.begin());
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			A.insert(x);
			B.insert(*A.rbegin());
			A.erase(A.find(*A.rbegin()));
		}
		else if(i==2) {
			cin>>y;
			ll v=*A.rbegin()+y;
			A.erase(A.find(*A.rbegin()));
			B.insert(v);
			A.insert(*B.begin());
			B.erase(B.begin());
			
		}
		else {
			cout<<*A.rbegin()<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

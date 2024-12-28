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

int T,N,V[202020],P[202020],X[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		multiset<ll> A,B;
		FOR(i,N) {
			cin>>V[i];
			B.insert(V[i]);
		}
		FOR(i,N) {
			cin>>x;
			X[i]=V[x-1];
		}
		ll ma=0;
		int num=0;
		for(i=1;i<=N;i++) {
			while(A.size()<i&&B.size()) {
				A.insert(*B.rbegin());
				B.erase(B.find(*B.rbegin()));
			}
			if(A.size()>=i&&*A.begin()*i>ma) {
				ma=*A.begin()*i;
				num=i;
			}
			if(B.count(X[i-1])) {
				B.erase(B.find(X[i-1]));
			}
			else {
				A.erase(A.find(X[i-1]));
			}
		}
		cout<<ma<<" "<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

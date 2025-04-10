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
ll A[303030];

ll L[303030],R[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	ll ret=0;
	if(N%2==0) {
		sort(A,A+N);
		FOR(i,N/2) ret+=A[i+N/2]-A[i];
	}
	else {
		multiset<int> S,T;
		ll D=0;
		L[0]=0;
		for(i=2;i<N;i+=2) {
			S.insert(A[i-2]);
			T.insert(A[i-1]);
			D+=A[i-1]-A[i-2];
			while(*S.rbegin()>*T.begin()) {
				x=*S.rbegin();
				y=*T.begin();
				S.erase(S.find(x));
				T.erase(T.find(y));
				S.insert(y);
				T.insert(x);
				D+=2*x-2*y;
			}
			L[i]=D;
		}
		S.clear(),T.clear();
		D=0;
		ret=L[N-1];
		for(i=N-3;i>=0;i-=2) {
			S.insert(A[i+2]);
			T.insert(A[i+1]);
			D+=A[i+1]-A[i+2];
			while(*S.rbegin()>*T.begin()) {
				x=*S.rbegin();
				y=*T.begin();
				S.erase(S.find(x));
				T.erase(T.find(y));
				S.insert(y);
				T.insert(x);
				D+=2*x-2*y;
			}
			R[i]=D;
			ret=max(ret,L[i]+R[i]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

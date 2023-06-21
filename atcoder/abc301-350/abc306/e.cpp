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
int A[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	multiset<int> X,Y;
	FOR(i,K) X.insert(0);
	FOR(i,N-K) Y.insert(0);
	ll sum=0;
	while(Q--) {
		int a,b;
		cin>>a>>b;
		a--;
		if(X.count(A[a])) {
			sum-=A[a];
			X.erase(X.find(A[a]));
			A[a]=b;
			X.insert(b);
			sum+=b;
		}
		else {
			Y.erase(Y.find(A[a]));
			A[a]=b;
			Y.insert(b);
		}
		
		if(X.size()&&Y.size()&&*X.begin()<*Y.rbegin()) {
			x=*X.begin();
			y=*Y.rbegin();
			X.erase(X.find(x));
			Y.erase(Y.find(y));
			sum-=x;
			sum+=y;
			X.insert(y);
			Y.insert(x);
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

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

int N,K;
int A[202020];

int B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	set<int> S;
	FOR(i,N) S.insert(i+1);
	FOR(i,N+1) B[i]=N+2;
	
	FOR(i,K) {
		cin>>A[i];
		S.erase(A[i]);
	}
	vector<int> R;
	FOR(i,K) {
		while(S.size()) {
			x=*S.begin();
			if(x>A[i]) break;
			
			y=lower_bound(B,B+N+1,x)-B;
			if(y>=i) break;
			B[y]=x;
			R.push_back(x);
			S.erase(x);
		}
		assert(B[i]>A[i]);
		B[i]=A[i];
		R.push_back(A[i]);
	}
	
	while(S.size()) {
		x=*S.rbegin();
		if(x<R.back()) break;
		S.erase(x);
		R.push_back(x);
		swap(R[R.size()-1],R[R.size()-2]);
		
	}
	while(S.size()) {
		x=*S.rbegin();
		S.erase(x);
		R.push_back(x);
	}
	
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

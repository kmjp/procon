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

int N,K,A[202020];
int L[202020],R[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	L[0]=1;
	FOR(i,N) {
		cin>>A[i+1];
		L[i+1]=L[i]&&(A[i+1]>=A[i]);
	}
	R[N+1]=1;
	A[N+1]=N+1;
	for(i=N;i>=1;i--) R[i]=R[i+1]&&(A[i]<=A[i+1]);
	
	multiset<int> S;
	FOR(i,N) {
		S.insert(A[i+1]);
		if(S.size()>K) S.erase(S.find(A[i+1-K]));
		if(S.size()==K) {
			if(L[i+2-K-1]&&R[i+2]&&A[i+2-K-1]<=*S.begin()&&*S.rbegin()<=A[i+2]) {
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

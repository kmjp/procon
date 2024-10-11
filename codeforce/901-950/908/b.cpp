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

int T,N,M,A[202020],B[202020];

int L[202020],R[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> V;
		FOR(i,N) {
			cin>>A[i];
			x=lower_bound(ALL(V),A[i])-V.begin();
			L[i]=x;
			if(x==V.size()) V.push_back(A[i]);
			else V[x]=A[i];
		}
		V.clear();
		int ma=0;
		for(i=N-1;i>=0;i--) {
			A[i]=-A[i];
			x=lower_bound(ALL(V),A[i])-V.begin();
			R[i]=x;
			if(x==V.size()) V.push_back(A[i]);
			else V[x]=A[i];
			A[i]=-A[i];
			ma=max(ma,1+L[i]+R[i]);
		}
		int LS=N,RS=-1;
		set<int> cand;
		FOR(i,N) if(ma==1+L[i]+R[i]) {
			if(R[i]==0) cand.insert(i);
		}
		multiset<int> X;
		FOR(i,M) {
			cin>>B[i];
			X.insert(B[i]);
		}
		FOR(i,N) {
			if(cand.count(i)) {
				while(X.size()&&*X.rbegin()>=A[i]) {
					cout<<*X.rbegin()<<" ";
					X.erase(X.find(*X.rbegin()));
				}
			}
			cout<<A[i]<<" ";
			if(cand.count(i)) {
				cand.erase(i);
				if(cand.empty()) {
					while(X.size()) {
						cout<<*X.rbegin()<<" ";
						X.erase(X.find(*X.rbegin()));
					}
				}
			}
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

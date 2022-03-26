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

int N,M;
int A[202020],B[202020],C[202020],D[202020];
map<int,vector<int>> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,M) cin>>C[i];
	FOR(i,M) cin>>D[i];
	
	FOR(i,N) cand[A[i]].push_back(B[i]);
	FOR(i,M) cand[C[i]].push_back(-D[i]);
	
	multiset<int> S;
	FORR2(a,b,cand) {
		vector<int> V;
		FORR(c,b) {
			if(c>0) S.insert(c);
			else V.push_back(-c);
		}
		sort(ALL(V));
		reverse(ALL(V));
		FORR(v,V) {
			auto it=S.lower_bound(v+1);
			if(it!=S.begin()) S.erase(--it);
		}
	}
	
	if(S.empty()) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

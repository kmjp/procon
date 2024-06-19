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

int T,N,P[2020];

vector<int> S(int L,int R) {
	vector<int> Q;
	int i;
	for(i=R;i<N;i++) Q.push_back(P[i]);
	for(i=R-1;i>=L;i--) Q.push_back(P[i]);
	FOR(i,L) Q.push_back(P[i]);
	return Q;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>P[i];
		vector<int> Q;
		FOR(i,N) Q.push_back(i+1);
		
		if(N>1) {
			if(P[0]==N) {
				FOR(i,N) if(P[i]==N-1) break;
				FOR(j,i) Q=max(Q,S(j,i));
			}
			else {
				FOR(i,N) if(P[i]==N) break;
				FOR(j,i) Q=max(Q,S(j,i));
			}
			Q=max(Q,S(i,i+1));
		}
		FORR(q,Q) cout<<q<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

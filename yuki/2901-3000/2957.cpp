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
int C[202020],X[202020],Y[202020];
vector<int> addf[202020];
vector<int> addb[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ret=0;

	cin>>N;
	FOR(i,N) {
		cin>>C[i]>>X[i]>>Y[i];
		ret+=min(X[i],Y[i]);
		
		if(X[i]>Y[i]) {
			addf[C[i]+1].push_back(X[i]-Y[i]);
		}
		if(X[i]<Y[i]) {
			addb[C[i]].push_back(Y[i]-X[i]);
		}
	}
	priority_queue<int> Q;
	for(i=1;i<=N;i++) {
		FORR(a,addf[i]) Q.push(a);
		if(Q.size()) {
			ret+=Q.top();
			Q.pop();
		}
	}
	while(Q.size()) Q.pop();
	
	for(i=N;i>=1;i--) {
		FORR(a,addb[i]) Q.push(a);
		if(Q.size()) {
			ret+=Q.top();
			Q.pop();
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

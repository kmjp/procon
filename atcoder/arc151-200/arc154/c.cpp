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

int T;
int N;
int A[5555],B[5555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		
		FOR(i,N) if(A[i]!=B[i]) break;
		if(i==N) {
			cout<<"Yes"<<endl;
			continue;
		}
		
		FOR(i,N) if(B[i]==B[(i+1)%N]) break;
		if(i==N) {
			cout<<"No"<<endl;
			continue;
		}
		
		vector<int> X,Y;
		FOR(i,N) {
			if(X.empty()||X.back()!=A[i]) X.push_back(A[i]);
			if(Y.empty()||Y.back()!=B[i]) Y.push_back(B[i]);
		}
		if(X.size()!=1&&X[0]==X.back()) X.pop_back();
		if(Y.size()!=1&&Y[0]==Y.back()) Y.pop_back();
		int ok=0;
		FOR(i,N) {
			rotate(X.begin(),X.begin()+1,X.end());
			int cur=0;
			FORR(x,X) if(cur<Y.size()&&Y[cur]==x) cur++;
			if(cur==Y.size()) ok=1;
		}
		
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N,Q;
int A[202020];
int B[202020];
int maA[202020],maB[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,int> MA,MB;
	FOR(i,N) {
		cin>>A[i];
		if(MA.count(A[i])==0) MA[A[i]]=i+1;
	}
	FOR(i,N) {
		cin>>B[i];
		if(MB.count(B[i])==0) MB[B[i]]=i+1;
		
		maB[i+1]=maB[i];
		if(MA.count(B[i])==0) {
			maB[i+1]=1<<20;
		}
		else {
			maB[i+1]=max(maB[i+1],MA[B[i]]);
		}
		
	}
	FOR(i,N) {
		maA[i+1]=maA[i];
		if(MB.count(A[i])==0) {
			maA[i+1]=1<<20;
		}
		else {
			maA[i+1]=max(maA[i+1],MB[A[i]]);
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		if(maA[x]>y||maB[y]>x) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

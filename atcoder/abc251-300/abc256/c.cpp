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

int H[3],W[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) {
		cin>>H[i];
		H[i]-=3;
	}
	FOR(i,3) {
		cin>>W[i];
		W[i]-=3;
	}
	
	ll ret=0;
	int A[3][3]={};
	for(A[0][0]=0;A[0][0]<=30;A[0][0]++)
	for(A[0][1]=0;A[0][1]<=30;A[0][1]++)
	for(A[1][0]=0;A[1][0]<=30;A[1][0]++)
	for(A[1][1]=0;A[1][1]<=30;A[1][1]++) {
		A[0][2]=H[0]-A[0][0]-A[0][1];
		A[1][2]=H[1]-A[1][0]-A[1][1];
		A[2][0]=W[0]-A[0][0]-A[1][0];
		A[2][1]=W[1]-A[0][1]-A[1][1];
		A[2][2]=H[2]-A[2][0]-A[2][1];
		if(A[2][2]!=W[2]-A[0][2]-A[1][2]) continue;
		int ok=1;
		FOR(y,3) FOR(x,3) {
			if(A[y][x]<0) ok=0;
		}
		ret+=ok;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

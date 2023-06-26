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
int L[101010],R[101010],X[101010],Y[101010];
int A[101010];

int C[101010];
int C2[101][101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>L[i]>>R[i]>>X[i]>>Y[i];
		x=L[i];
		if(x%X[i]<=Y[i]) x+=Y[i]-(x%X[i]);
		else x+=X[i]-(x%X[i]-Y[i]);
		
		y=R[i];
		if(y%X[i]>=Y[i]) y-=(y%X[i])-Y[i];
		else y-=(y%X[i])+(X[i]-Y[i]);
		
		if(X[i]>100) {
			for(j=x;j<=y;j+=X[i]) C[j]++;
		}
		else {
			if(y>=x) C2[X[i]][x]++,C2[X[i]][y+X[i]]--;
		}
	}
	
	for(i=1;i<=100;i++) {
		for(j=1;j<=100000;j++) {
			C[j]+=C2[i][j];
			C2[i][j+i]+=C2[i][j];
		}
	}
	while(M--) {
		cin>>x;
		cout<<C[x]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

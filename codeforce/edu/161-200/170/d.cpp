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
int R[2020202];
vector<int> A[5050];

int from[5050],to[5050];
int X[5050],Y[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	x=0;
	FOR(i,N) {
		cin>>y;
		if(y==0) x++;
		else A[x].push_back(y);
	}
	
	FOR(x,M+1) from[x]=-1<<25;
	from[0]=0;
	FOR(i,M) {
		for(j=0;j<=M;j++) to[j]=from[j], from[j]=-1<<25;
		for(j=0;j<=M;j++) from[j]=max(from[j],to[j]),from[j+1]=max(from[j+1],to[j]);
		
		ZERO(X);
		ZERO(Y);
		FORR(a,A[i+1]) {
			if(a<0) X[-a]++;
			else Y[a]++;
		}
		FOR(j,M+1) X[j+1]+=X[j],Y[j+1]+=Y[j];
		
		FOR(j,i+2) from[j]+=X[j]+Y[i+1-j];
	}
	int ret=0;
	FOR(j,M+1) ret=max(ret,from[j]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

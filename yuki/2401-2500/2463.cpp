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
int V[505][505];

int num(vector<int> X) {
	int x=0;
	while(x<5&&X[x]<=5) x++;
	
	int cur=5;
	int sum=0;
	while(x<5) {
		int nex=X[x];
		int step=5-x;
		int a=(nex-cur+step-1)/step;
		sum+=a;
		cur+=a*step;
		while(x<5&&X[x]<=cur) x++;
	}
	return sum;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N*M) {
		cin>>x>>y;
		V[y-1][x-1]=i+1;
	}
	
	int mi=1<<30;
	FOR(i,M) {
		FOR(j,N-3) {
			vector<int> X;
			FOR(x,5) X.push_back(V[i][(j+x)%N]);
			sort(ALL(X));
			mi=min(mi,num(X));
		}
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

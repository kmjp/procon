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

int T,N;
int A[2020];

int F[30];

int ask(int i) {
	if(A[i]==-1) {
		cout<<"? "<<(i+1)<<endl;
		cin>>A[i];
	}
	return A[i];
}

int dfs(int L,int R) {
	if(R-L<=2) {
		int ma=-1;
		int i;
		for(i=L;i<=R;i++) ma=max(ma,ask(i));
		return ma;
	}
	int i;
	FOR(i,30) if(F[i]-1==R-L+1) break;
	assert(i<30);
	int x=L+F[i-2]-1;
	int y=L+F[i-1]-1;
	int v1=ask(x);
	int v2=ask(y);
	if(v1<v2) return dfs(x+1,R);
	else return dfs(L,y-1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=1;
	for(i=2;i<=29;i++) {
		F[i]=F[i-1]+F[i-2];
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,1600) A[i]=-(i+3);
		FOR(i,N) A[i]=-1;
		
		x=dfs(0,1595);
		cout<<"! "<<x<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

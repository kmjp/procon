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

int N,L;
int A[202];
ll V;
map<int,double> memo[202][202];

double dfs(int n1,int n0,int L) {
	if(L<=0) return 0;
	if(n1+n0==0) return 0;
	if(memo[n1][n0].count(L)) return memo[n1][n0][L];
	double ret=0;
	
	if(n1) {
		double ok=1.0*n1/(n1+n0*2);
		//1–‡–Ú‚Å’m‚Á‚Ä‚¢‚é
		ret+=ok*(1+dfs(n1-1,n0,L));
	}
	if(n0) {
		double ng1=1.0*(2*n0)/(n1+n0*2);
		//2–‡–Ú‚Í’m‚Á‚Ä‚¢‚é
		double ngok=1.0*1/(n1+1+n0*2-2);
		ret+=ng1*ngok*(1+dfs(n1,n0-1,L));
		double ok1=1.0*(n1)/(n1+1+n0*2-2);
		if(L>1) ret+=ng1*ok1*(1+dfs(n1,n0-1,L-1));
		if(n0>1) {
			//2–‡–Ú‚Æ‚à‚µ‚ç‚È‚¢
			double ng2=1.0*((n0-1)*2)/(n1+1+(n0*2-2));
			ret+=ng1*ng2*dfs(n1+2,n0-2,L-1);
		}
	}
		
	
	return memo[n1][n0][L]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>A[i];
		V+=A[i];
	}
	
	_P("%.12lf\n",dfs(0,N,L)*V/N);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

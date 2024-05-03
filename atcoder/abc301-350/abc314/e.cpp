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
int C[101],P[101];
vector<int> S[101];

double memo[102];

double hoge(int M) {
	if(M<=0) return 0;
	if(memo[M]>=-0.5) return memo[M];
	double mi=1e9;
	
	int i;
	FOR(i,N) {
		int num=0;
		int ze=0;
		double sum=0;
		FORR(s,S[i]) {
			if(s==0) ze++;
			else {
				num++;
				sum+=hoge(M-s);
			}
		}
		
		double co=1.0*C[i]*(num+ze)/num+sum/num;
		mi=min(mi,co);
	}
	
	
	return memo[M]=mi;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>C[i]>>P[i];
		FOR(j,P[i]) {
			cin>>x;
			S[i].push_back(x);
		}
	}
	FOR(i,M+1) memo[i]=-1;
	_P("%.12lf\n",hoge(M));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

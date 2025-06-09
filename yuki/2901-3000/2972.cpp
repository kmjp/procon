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

int T,N,P,Q;
int isP[101010];
int S[101010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=100000;i++) {
		S[i]+=S[i-1];
		if(isP[i]==0) {
			S[i]++;
			for(j=i;j<=100000;j+=i) isP[j]=1;
		}
	}
		
	
	cin>>T;
	while(T--) {
		cin>>N>>P>>Q;
		
		int np=S[N];
		int nq=N-S[N];
		
		double yes=np*P+nq*(100-Q);
		double npyes=np*P;
		_P("%.12lf\n",npyes/yes);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

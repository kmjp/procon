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

int N,K;
char P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x>>s;
		P[x-1]=s[0];
	}
	string S;
	for(i=0;i<(N+2)/3*3;i+=3) {
		vector<char> V;
		int C[3]={1,1,1};
		FOR(j,3) {
			if(P[i+j]=='R'&&C[0]) {
				C[0]=0;
				S+='R';
			}
			if(P[i+j]=='G'&&C[1]) {
				C[1]=0;
				S+='G';
			}
			if(P[i+j]=='B'&&C[2]) {
				C[2]=0;
				S+='B';
			}
		}
		if(C[0]) S+="R";
		if(C[1]) S+="G";
		if(C[2]) S+="B";
		
		
	}
	cout<<S.substr(0,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

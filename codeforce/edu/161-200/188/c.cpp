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

int T;
ll A,B,C,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>M;
		ll V[3]={};
		V[0]=M/A*6;
		V[1]=M/B*6;
		V[2]=M/C*6;
		ll AB=A*B/__gcd(A,B);
		ll BC=C*B/__gcd(C,B);
		ll CA=C*A/__gcd(C,A);
		V[0]-=M/AB*3+M/CA*3;
		V[1]-=M/AB*3+M/BC*3;
		V[2]-=M/CA*3+M/BC*3;
		ll ABC=AB*C/__gcd(AB,C);
		V[0]+=M/ABC*2;
		V[1]+=M/ABC*2;
		V[2]+=M/ABC*2;
		cout<<V[0]<<" "<<V[1]<<" "<<V[2]<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

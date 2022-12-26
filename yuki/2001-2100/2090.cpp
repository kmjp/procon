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

string A[6];
int B[6];
map<string,int> M;
int nand(int a,int b) {
	return !(a&b);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) {
		cin>>A[i];
		M[A[i]]=i;
	}
	FOR(i,6) B[i]=M[A[i]];
	
	int mask;
	FOR(mask,1<<6) {
		int C[6];
		FOR(i,6) C[i]=(mask>>B[i])&1;
		if(nand(nand(nand(C[0],C[1]),C[2]),nand(nand(C[3],C[4]),C[5]))==1) {
			cout<<"YES"<<endl;
			return;
		}
		
	}
	cout<<"NO"<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

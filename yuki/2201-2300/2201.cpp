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

string S;
vector<int> A;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) {
		if(c=='l'||c=='o') A.push_back(0);
		else if(c=='a'||c=='s') A.push_back(1);
		else A.push_back(2);
	}
	
	int ok=0;
	int mask=0;
	FOR(mask,256) {
		int ng=0;
		FOR(i,8) if((mask&(1<<i)) && A[i]==2) ng=1;
		if(ng) continue;
		int C[3]={};
		FOR(i,8) {
			if(A[i]==0) {
				if(mask&(1<<i)) C[0]++;
				else C[2]++;
			}
			if(A[i]==1) {
				if(mask&(1<<i)) C[1]++;
				else C[2]++;
			}
			if(A[i]==2) {
				C[2]++;
			}
		}
		if(C[0]&&C[1]&&C[2]) ok++;
	}
	
	cout<<ok<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

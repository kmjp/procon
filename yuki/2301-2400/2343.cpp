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
int N;
int A[202020];

void dfs(vector<double> A) {
	if(A.size()==1) {
		if(A[0]<0.51) cout<<A[0]<<endl;
	}
	else {
		int i,j;
		FOR(i,A.size()-1) {
			vector<double> B;
			FOR(j,A.size()) {
				if(j==i+1) {
					B.back()=(B.back()+A[j])/2;
				}
				else {
					B.push_back(A[j]);
				}
			}
			dfs(B);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	vector<double> V={1,0,1,0,1,0,1};
	dfs(V);
	return;
	*/
	
	cin>>T;
	while(T--) {
		cin>>N;
		int C[2]={},D[2]={};
		FOR(i,N) {
			cin>>A[i];
			if(i&&A[i]==A[i-1]) C[A[i]]++;
			D[A[i]]++;
		}
		
		if(A[0]!=A[N-1]||C[A[0]^1]||D[A[0]^1]>=4) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

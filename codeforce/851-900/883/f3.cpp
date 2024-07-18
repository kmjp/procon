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
int A[200];
int B[200];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		int tar;
		while(1) {
			cout<<"- 0"<<endl;
			FOR(i,N) cin>>B[i];
			int C[10]={};
			FOR(i,N) C[A[i]]--,C[B[i]]++;
			FOR(i,10) if(C[i]>0) break;
			if(i==10) continue;
			tar=i;
			vector<int> V;
			FOR(j,N) if(B[j]!=tar) V.push_back(j+1);
			cout<<"- "<<V.size();
			FORR(v,V) cout<<" "<<v;
			cout<<endl;
			N-=V.size();
			FOR(i,N) cin>>A[i];
			break;
		}
		while(1) {
			FOR(i,N) if(A[i]!=tar) break;
			if(i!=N) break;
			cout<<"- 0"<<endl;
			FOR(i,N) cin>>A[i];
		}
		cout<<"! "<<i+1<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

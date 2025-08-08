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

int N,A[202020];
int C[2],Q,X;
set<int> S;

int is(int i) {
	
	if(i==0) return A[i]==0&&A[i+1]==0;
	if(i<=0||i>=N-1) return 0;
	return A[i-1]&&A[i]==0&&A[i+1]==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
	}
	FOR(i,N) if(is(i)) S.insert(i);
	
	cin>>Q;
	while(Q--) {
		cin>>X;
		X--;
		for(i=X-3;i<=X+3;i++) S.erase(i);
		C[A[X]]--;
		A[X]^=1;
		C[A[X]]++;
		for(i=X-3;i<=X+3;i++) if(is(i)) S.insert(i);
		
		if(C[1]==0) {
			cout<<2<<endl;
		}
		else if(C[1]==1) {
			x=1;
			if(A[0]==1||A[N-1]==1) x=3;
			else if(A[1]==1||A[N-2]==1) {
				if(N==3) x=3;
				else x=4;
			}
			else {
				x=5;
			}
			cout<<x<<endl;
		}
		else if(C[1]==N) {
			cout<<N<<endl;
		}
		else if(S.size()==0) {
			int num=1;
			if(A[0]&&A[N-1]) num=2;
			else {
				if(A[0]==0) num++;
				if(A[N-1]==0) num++;
			}
			cout<<num<<endl;
		}
		else {
			int num=2*S.size()+S.size()-1;
			if(A[0]==0&&A[1]==1) num+=2;
			if(A[0]) num++;
			if(A[N-1]==0&&A[N-2]==1) num+=2;
			if(A[N-1]) num++;
			cout<<num<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

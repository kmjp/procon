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

int T,N,A[101010];
int L[101010],R[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> B;
		x=0;
		FOR(i,N) {
			cin>>A[i];
			B.insert(A[i]);
			while(B.count(x)) x++;
			L[i]=x;
		}
		x=0;
		B.clear();
		for(i=N-1;i>=1;i--) {
			B.insert(A[i]);
			while(B.count(x)) x++;
			R[i]=x;
			if(R[i]==L[i-1]) break;
		}
		if(i==0) {
			cout<<-1<<endl;
		}
		else {
			cout<<2<<endl;
			cout<<"1 "<<i<<endl;
			cout<<i+1<<" "<<N<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

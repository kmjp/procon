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

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> A={1,2};
	vector<int> B={1,2,-3,2,4,-5,-2};
	
	if(N%2==0) {
		while(A.size()<N) {
			x=A[A.size()-2];
			y=A[A.size()-1];
			A.push_back(-y);
			A.push_back(x-y);
		}
		cout<<"YES"<<endl;
		FORR(a,A) cout<<a<<" ";
		cout<<endl;
	}
	else {
		if(N<7) {
			cout<<"NO"<<endl;
			return;
		}
		while(B.size()<N) {
			x=B[B.size()-2];
			y=B[B.size()-1];
			B.push_back(-y);
			B.push_back(x-y);
		}
		cout<<"YES"<<endl;
		FORR(a,B) cout<<a<<" ";
		cout<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

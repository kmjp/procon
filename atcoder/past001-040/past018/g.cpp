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
int A[202020],B[202020];
vector<int> NG;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) if(A[i]!=B[i]) NG.push_back(i);
	int ok=0;
	FOR(i,N-1) if(A[i]==A[i+1]) ok=1;
	if(NG.empty()) {
		cout<<"Yes"<<endl;
	}
	else if(NG.size()==1||NG.size()>4) {
		cout<<"No"<<endl;
	}
	else if(NG.size()==2) {
		x=NG[0];
		y=NG[1];
		if(x+1==y&&A[x]==B[y]&&A[y]==B[x]&&(ok||(x&&A[x-1]==A[y])||(y+1<N&&A[x]==A[y+1]))) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	else if(NG.size()==3) {
		x=NG[0];
		y=NG[1];
		k=NG[2];
		if(x+2==k&&A[x]==B[k]&&A[y]==B[x]&&A[k]==B[y]) {
			cout<<"Yes"<<endl;
		}
		else if(x+2==k&&A[x]==B[y]&&A[y]==B[k]&&A[k]==B[x]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	else {
		x=NG[0];
		y=NG[1];
		i=NG[2];
		j=NG[3];
		if(x+1==y&&A[x]==B[y]&&A[y]==B[x]&&i+1==j&&A[i]==B[j]&&A[j]==B[i]) {
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

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
int A[202020];

int win[15][15][2];

int hoge(int a,int b,int c) {
	if(a==0&&b==0) return 0;
	if(a+b==1) return 1;
	if(a+b==2&&c==0) return 0;
	if(win[a][b][c]>=0) return win[a][b][c];
	int ok=0;
	if(c&&hoge(a,b,0)==0) ok=1;
	if(a&&hoge(a-1,b,c)==0) ok=1;
	if(b&&hoge(a,b-1,c^1)==0) ok=1;
	win[a][b][c]=ok;
	return win[a][b][c];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int C[2]={};
	FOR(i,N) {
		cin>>A[i];
		C[A[i]%2]++;
	}
	sort(A,A+N);
	
	MINUS(win);
	/*
	FOR(x,14) {
		cout<<x<<" ";
		FOR(y,14) cout<<hoge(x,y,0);
		cout<<" ";
		FOR(y,14) cout<<hoge(x,y,1);
		cout<<endl;
	}
	*/
	if(N>=10) {
		if(C[1]%2) cout<<"Fennec"<<endl;
		else cout<<"Snuke"<<endl;
	}
	else if(hoge(C[1],C[0],0)) {
		cout<<"Fennec"<<endl;
	}
	else {
		cout<<"Snuke"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

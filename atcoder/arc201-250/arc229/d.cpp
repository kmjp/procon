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

int T,K,A[202020];

int win[10][10][10];
int win4[10][10][10][10];

int hoge(int a,int b,int c) {
	if(win[a][b][c]>=0) return win[a][b][c];
	int ret=0;
	int x,y,z;
	for(x=2;x<=a;x++) if(hoge(a-x,b,c)==0) ret=1;
	for(x=2;x<=b;x++) if(hoge(a,b-x,c)==0) ret=1;
	for(x=2;x<=c;x++) if(hoge(a,b,c-x)==0) ret=1;
	for(x=1;x<=a;x++) for(y=1;y<=b;y++)if(hoge(a-x,b-y,c)==0) ret=1;
	for(x=1;x<=a;x++) for(z=1;z<=c;z++)if(hoge(a-x,b,c-z)==0) ret=1;
	for(y=1;y<=b;y++) for(z=1;z<=c;z++)if(hoge(a,b-y,c-z)==0) ret=1;
	
	return win[a][b][c]=ret;
}
int hoge2(int a,int b,int c,int d) {
	if(a<0||b<0||c<0||d<0) return 1;
	if(win4[a][b][c][d]>=0) return win4[a][b][c][d];
	int ret=0;
	int x,y,z,w;
	for(x=3;x<=a;x++) if(hoge2(a-x,b,c,d)==0) ret=1;
	for(x=3;x<=b;x++) if(hoge2(a,b-x,c,d)==0) ret=1;
	for(x=3;x<=c;x++) if(hoge2(a,b,c-x,d)==0) ret=1;
	for(x=3;x<=d;x++) if(hoge2(a,b,c,d-x)==0) ret=1;
	for(x=1;x<=10;x++) for(y=1;y<=10;y++) if(x+y>=3) {
		if(hoge2(a-x,b-y,c,d)==0) ret=1;
		if(hoge2(a-x,b,c-y,d)==0) ret=1;
		if(hoge2(a-x,b,c,d-y)==0) ret=1;
		if(hoge2(a,b-x,c-y,d)==0) ret=1;
		if(hoge2(a,b-x,c,d-y)==0) ret=1;
		if(hoge2(a,b,c-x,d-y)==0) ret=1;
	}
	for(x=1;x<=10;x++) for(y=1;y<=10;y++) for(z=1;z<=10;z++) {
		if(hoge2(a-x,b-y,c-z,d)==0) ret=1;
		if(hoge2(a-x,b-y,c,d-z)==0) ret=1;
		if(hoge2(a-x,b,c-y,d-z)==0) ret=1;
		if(hoge2(a,b-x,c-y,d-z)==0) ret=1;
	}
	
	return win4[a][b][c][d]=ret;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	/*
	MINUS(win);
	MINUS(win4);
	for(x=1;x<=9;x++) for(y=x;y<=9;y++) for(z=y;z<=9;z++) if(hoge(x,y,z)==0) cout<<x<<" "<<y<<" "<<z<<" "<<hoge(x,y,z)<<endl;
	for(x=1;x<=9;x++) for(y=x;y<=9;y++) for(z=y;z<=9;z++) for(k=z;k<=9;k++)  if(hoge2(x,y,z,k)==0) cout<<x<<" "<<y<<" "<<z<<" "<<k<<" "<<hoge2(x,y,z,k)<<endl;
	*/
	
	cin>>T;
	while(T--) {
		cin>>K;
		FOR(i,K+1) cin>>A[i];
		sort(A,A+K+1);
		if(A[0]%K) {
			cout<<"Alice"<<endl;
			continue;
		}
		ll sum=0;
		FOR(i,K+1) sum+=A[i]-A[0];
		if(sum>=K) {
			cout<<"Alice"<<endl;
		}
		else {
			cout<<"Bob"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

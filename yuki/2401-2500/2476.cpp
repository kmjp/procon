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

int win(ll H,ll W,int R,int C) {
	R--,C--;
	if(H>W) swap(H,W), swap(R,C);
	if(H==1) return 0;
	if(H==2) {
		return (C/2%2)||((W-1-C)/2%2);
	}
	if(H*W%2==0) return 1;
	if((R+C)%2) return 1;
	if(H==3&&W==3) return !((R==1)&(C==1));
	if(H==3&&W==5) return ((C==2)&(R!=1));
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--){
		int H,W,X,Y;
		cin>>H>>W>>X>>Y;
		if(win(H,W,X,Y)) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

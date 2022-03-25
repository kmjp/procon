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

ll N;
ll X[101010],Y[101010];
ll AX,AY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	X[N]=X[0];
	Y[N]=Y[0];
	cin>>AX>>AY;
	FOR(i,N+1) {
		X[i]-=AX;
		Y[i]-=AY;
	}
	
	int num=0;
	FOR(i,N) {
		if(Y[i]==0&&Y[i+1]==0) continue;
		if(Y[i]==0) {
			if(X[i]<0) continue;
			if(Y[i+1]>0) num++;
		}
		else if(Y[i+1]==0) {
			if(X[i+1]<0) continue;
			if(Y[i]>0) num++;
		}
		else if((Y[i]>0&&Y[i+1]<0)||(Y[i]<0&&Y[i+1]>0)) {
			ll a=abs(Y[i+1])*X[i]+abs(Y[i])*X[i+1];
			if(a>0) num++;
		}
		
		
	}
	if(num%2) {
		cout<<"INSIDE"<<endl;
	}
	else {
		cout<<"OUTSIDE"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

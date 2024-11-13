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

double a,b;
ll A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>a>>b;
	A=round(a*10000);
	B=round(b*10000);
	
	if(a==1||b==0) {
		cout<<"Yes"<<endl;
		return;
	}
	
	if(A<10000) {
		if(100000000%A) {
			cout<<"No"<<endl;
			return;
		}
		A=100000000/A;
		B=-B;
	}
	
	if(B<0) {
		cout<<"No"<<endl;
		return;
	}
	if(A%10000) {
		cout<<"No"<<endl;
		return;
	}
	A/=10000;
	B%=10000;
	int ma=1;
	for(i=2;i*i<=A;i++) {
		x=0;
		y=A;
		while(y%i==0) {
			y/=i;
			x++;
		}
		if(y==1) ma=max(ma,x);
	}
	if(B*ma%10000==0) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

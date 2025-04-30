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

int T,N;
int ask(int a,int b) {
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>a;
	return a;
}

void ans(int a) {
	cout<<"! "<<a<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		while(N>5) {
			x=ask(N-1,N);
			y=ask(N,N-1);
			if(x!=y) {
				if(ask(N-2,N)==ask(N,N-2)) ans(N-1);
				else ans(N);
				break;
			}
			N-=2;
		}
		if(N>5) continue;
		if(N==3) {
			if(ask(1,2)==ask(2,1)) {
				ans(3);
			}
			else if(ask(1,3)==ask(3,1)) {
				ans(2);
			}
			else {
				ans(1);
			}
		}
		if(N==4) {
			x=(ask(1,2)==ask(2,1));
			y=(ask(1,3)==ask(3,1));
			if(x==0&&y==0) ans(1);
			if(x==0&&y==1) ans(2);
			if(x==1&&y==0) ans(3);
			if(x==1&&y==1) ans(4);
			
		}
		if(N==5) {
			int a12=ask(1,2);
			int a31=ask(3,1);
			x=a12+ask(2,3)+a31;
			if((3-x)%2==0) {
				if(ask(1,4)==ask(4,1)) {
					ans(5);
				}
				else {
					ans(4);
				}
			}
			else {
				if(a12==ask(2,1)) {
					ans(3);
				}
				else if(a31==ask(1,3)) {
					ans(2);
				}
				else {
					ans(1);
				}
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

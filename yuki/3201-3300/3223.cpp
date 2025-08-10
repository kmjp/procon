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

int N,K,X,Y;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X>>Y;
	if(Y==0) {
		cout<<"No"<<endl;
	}
	else if(K==1) {
		if(Y>=X+N-1) {
			cout<<"Yes"<<endl;
			FOR(i,N-1) cout<<X+i<<" ";
			cout<<Y<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	else if(X==0) {
		if(N==K+1) {
			cout<<"Yes"<<endl;
			FOR(i,N-1) cout<<"0 ";
			cout<<Y<<endl;
		}
		else if(N==K+2) {
			if(Y==1) {
				cout<<"No"<<endl;
			}
			else {
				cout<<"Yes"<<endl;
				FOR(i,N-2) cout<<"0 ";
				cout<<"1 "<<Y<<endl;
			}
		}
		else {
			cout<<"Yes"<<endl;
			cout<<"0 1";
			for(i=2;i<N-1;i++) {
				if(K%2==0) cout<<" 3";
				else {
					x=(i-2)%K;
					if(x==K-1) cout<<" 3";
					else if(x==K-2) cout<<" 2";
					else cout<<" 1";
				}
			}
			cout<<" "<<Y<<endl;
		}
	}
	else {
		FOR(i,1<<20) {
			if(i&&(X^i)&&(X^i)<1<<20) {
				x=i;
				y=X^i;
			}
		}
		cout<<"Yes"<<endl;
		FOR(i,N-1) {
			k=i%K;
			r=X;
			if(K%2&&k==K-2) r=x;
			if(K%2&&k==K-1) r=y;
			cout<<r<<" ";
		}
		cout<<Y<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

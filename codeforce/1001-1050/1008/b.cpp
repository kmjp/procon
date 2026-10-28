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
ll X,Y,M;

int XX=15346;
int YY=2978;

int hoge(int a) {
	cout<<a<<endl;
	cin>>a;
	return a;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int X=0,Y=0;
		FOR(i,30) {
			if(i%2==0) X|=1<<i;
			else Y|=1<<i;
		}
		int A=hoge(X);
		int B=hoge(Y);
		
		int num[31]={};
		int V=0,W=0;
		
		if(B%2==0) {
			if((B>>1)%2) {
				V|=1;
				W|=1;
			}
		}
		else {
			V|=1;
		}
		for(i=1;i<30;i++) {
			if((A>>i)%2) {
				if((A>>(i+1))%2) {
					V|=1<<i;
					W|=1<<i;
				}
			}
			else {
				V|=1<<i;
			}
			swap(A,B);
		}
		swap(A,B);
		
		assert((V|X)+(W|X)==A);
		assert((V|Y)+(W|Y)==B);
		cout<<"!"<<endl;
		cin>>x;
		cout<<((x|V)+(x|W))<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

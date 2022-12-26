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

int N,M;

int C[161616];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	for(x=0;x<=M;x++) {
		for(y=0;y<=x;y++) {
			int num=2;
			if(x==y) num=1;
			for(i=0;i<=M;i++) {
				int S=x*x+y*y+i*i+x*y+x*i+y*i;
				for(j=0;j<=M&&S+j*(x+y+j+i)<=N;j++) C[S+j*(x+y+j+i)]+=num;
			}
		}
	}
	FOR(i,N+1) cout<<C[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

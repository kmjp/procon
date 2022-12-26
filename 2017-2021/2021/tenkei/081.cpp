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

int N,K;
int A[5050][5050];
int S[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		A[y][x]++;
	}
	for(y=1;y<=5001;y++) {
		for(x=1;x<=5001;x++) {
			S[y][x]=S[y-1][x]+S[y][x-1]-S[y-1][x-1]+A[y][x];
		}
	}
	int ma=0;
	for(y=1;y+K<=5001;y++) {
		for(x=1;x+K<=5001;x++) {
			k=S[y+K][x+K]+S[y-1][x-1]-S[y+K][x-1]-S[y-1][x+K];
			ma=max(ma,k);
		}
	}
	cout<<ma<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

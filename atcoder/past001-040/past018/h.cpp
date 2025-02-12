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

string S[303];
int A[303][303];

int num(int L,int R,int U,int D) {
	return A[D][R]-A[U][R]-A[D][L]+A[U][L];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) {
			A[y+1][x+1]=A[y][x+1]+A[y+1][x]-A[y][x]+(S[y][x]=='#');
		}
	}
	
	int ma=0;
	FOR(y,N) {
		FOR(x,N) {
			for(k=3;y+k<=N&&x+k<=N;k++) {
				if(num(x,x+k,y,y+1)!=k) continue;
				if(num(x,x+k,y+k-1,y+k)!=k) continue;
				if(num(x,x+1,y,y+k)!=k) continue;
				if(num(x,x+k,y,y+k)!=3*k-2) continue;
				ma=max(ma,k-2);
			}
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

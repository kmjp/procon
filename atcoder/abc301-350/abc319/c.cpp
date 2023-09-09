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

int C[3][3];
int D[3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	FOR(y,3) FOR(x,3) {
		cin>>C[y][x];
		V.push_back(y*3+x);
	}
	
	int ok=0,sum=0;
	do {
		sum++;
		MINUS(D);
		int ng=0;
		FOR(i,3) {
			if(C[i][0]==C[i][1]&&V[i*3+0]>V[i*3+2]&&V[i*3+1]>V[i*3+2]) ng=1;
			if(C[i][0]==C[i][2]&&V[i*3+0]>V[i*3+1]&&V[i*3+2]>V[i*3+1]) ng=1;
			if(C[i][1]==C[i][2]&&V[i*3+1]>V[i*3+0]&&V[i*3+2]>V[i*3+0]) ng=1;
			if(C[0][i]==C[1][i]&&V[0+i]>V[6+i]&&V[3+i]>V[6+i]) ng=1;
			if(C[0][i]==C[2][i]&&V[0+i]>V[3+i]&&V[6+i]>V[3+i]) ng=1;
			if(C[1][i]==C[2][i]&&V[3+i]>V[0+i]&&V[6+i]>V[0+i]) ng=1;
			
			if(C[0][0]==C[1][1]&&V[0+0]>V[6+2]&&V[3+1]>V[6+2]) ng=1;
			if(C[0][0]==C[2][2]&&V[0+0]>V[3+1]&&V[6+2]>V[3+1]) ng=1;
			if(C[1][1]==C[2][2]&&V[3+1]>V[0+0]&&V[6+2]>V[0+0]) ng=1;
			
			if(C[0][2]==C[1][1]&&V[0+2]>V[6+0]&&V[3+1]>V[6+0]) ng=1;
			if(C[0][2]==C[2][0]&&V[0+2]>V[3+1]&&V[6+0]>V[3+1]) ng=1;
			if(C[1][1]==C[2][0]&&V[3+1]>V[0+2]&&V[6+0]>V[0+2]) ng=1;
			
		}
		if(ng==0) ok++;
	}
	 while(next_permutation(ALL(V)));
	
	_P("%.12lf\n",1.0*ok/sum);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

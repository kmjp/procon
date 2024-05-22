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
string S;
int from[27][27][5250];
int to[27][27][5250];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	ZERO(from);
	from[0][0][2625]=1;
	int C[2]={};
	int step=0;
	FORR(c,S) {
		ZERO(to);
		step++;
		i=c-'0';
		FOR(x,min(step,26)) FOR(y,min(step,26)) FOR(k,5240) if(from[x][y][k]) {
			to[x+(i==1)][y][k+C[1]+y-x]=1;
			to[x][y+(i==0)][k-(C[0]+x-y)]=1;
		}
		C[c-'0']++;
		swap(from,to);
	}
	FOR(x,51) if(from[x][x][2625]) {
		cout<<x<<endl;
		return;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

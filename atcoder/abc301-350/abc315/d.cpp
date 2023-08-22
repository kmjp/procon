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

int H,W;
string S[2020];

int R[2020][26];
int C[2020][26];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) c-='a';
		FOR(x,W) {
			R[y][S[y][x]]++;
			C[x][S[y][x]]++;
		}
	}
	queue<int> Q[2];
	FOR(y,H) {
		k=j=0;
		FOR(i,26) {
			if(R[y][i]>0) k++;
			if(R[y][i]>1) j++;
		}
		if(k==1&&j==1) {
			FOR(i,26) R[y][i]=-1;
			Q[0].push(y);
		}
	}
	FOR(x,W) {
		k=j=0;
		FOR(i,26) {
			if(C[x][i]>0) k++;
			if(C[x][i]>1) j++;
		}
		if(k==1&&j==1) {
			FOR(i,26) C[x][i]=-1;
			Q[1].push(x);
		}
	}
	while(Q[0].size()||Q[1].size()) {
		queue<int> NQ[2];
		while(Q[0].size()) {
			y=Q[0].front();
			Q[0].pop();
			FOR(x,W) if(C[x][0]>=0) {
				C[x][S[y][x]]--;
				k=j=0;
				FOR(i,26) {
					if(C[x][i]>0) k++;
					if(C[x][i]>1) j++;
				}
				if(k==1&&j==1) {
					FOR(i,26) C[x][i]=-1;
					NQ[1].push(x);
				}
			}
		}
		while(Q[1].size()) {
			x=Q[1].front();
			Q[1].pop();
			FOR(y,H) if(R[y][0]>=0) {
				R[y][S[y][x]]--;
				k=j=0;
				FOR(i,26) {
					if(R[y][i]>0) k++;
					if(R[y][i]>1) j++;
				}
				if(k==1&&j==1) {
					FOR(i,26) R[y][i]=-1;
					NQ[0].push(y);
				}
			}
		}
		swap(Q[0],NQ[0]);
		swap(Q[1],NQ[1]);
	}
	int ret=0;
	FOR(y,H) FOR(x,W) if(R[y][0]>=0&&C[x][0]>=0) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

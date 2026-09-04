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

int nex[1010][26];
int len[1010][26];

int cand[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	//ŽüŠú
	int per=N;
	for(i=1;i<=N;i++) if(N%i==0) {
		for(j=0;j<N;j+=i) if(S.substr(0,i)!=S.substr(j,i)) break;
		if(j==N) per=min(per,i);
	}
	FOR(i,N) {
		int C[26]={};
		FOR(x,26) C[x]=101010;
		FOR(j,N) {
			chmin(C[S[(i+1+j)%N]-'a'],j+1);
		}
		FOR(x,26) {
			if(C[x]==101010) {
				len[i][x]=nex[i][x]=101010;
			}
			else {
				nex[i][x]=(i+C[x])%N;
				len[i][x]=C[x];
			}
		}
	}
	
	for(l=1;l<N;l++) {
		FOR(i,N) {
			int c=0;
			int dif=199999;
			FOR(j,26) if(len[i][j]!=101010) {
				int d=len[(i+l)%N][j]-len[i][j];
				if(d<dif) {
					dif=d;
					c=j;
				}
			}
			cand[i][l]=c;
		}
	}
	string ret;
	x=0;
	y=per-1;
	while(x!=y) {
		int d=y-x;
		if(d<0) d+=N;
		int c=cand[x][d];
		ret+='a'+c;
		x=nex[x][c];
		y=nex[y][c];
	}
	cout<<N/per<<endl;
	cout<<ret.size()<<endl;
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

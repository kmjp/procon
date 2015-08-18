#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[101];
int M;
string B[101];

vector<int> P;
int R[101][101];
int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	cin>>M;
	FOR(y,M) cin>>B[y];
	FOR(x,M) {
		for(y=M-1;y>=0;y--) if(B[y][x]!='#') {
			D[y][x]=1+D[y+1][x];
			if(D[y][x]>1 && (y==0 || B[y-1][x]=='#')) P.push_back(y*100+x);
		}
	}
	FOR(y,M) {
		for(x=M-1;x>=0;x--) if(B[y][x]!='#') {
			R[y][x]=1+R[y][x+1];
			if(R[y][x]>1 && (x==0 || B[y][x-1]=='#')) P.push_back(10000+y*100+x);
		}
	}
	sort(ALL(P));
	do {
		int ng=0;
		FOR(i,N) {
			int len;
			if(P[i]>=10000) len=R[(P[i]-10000)/100][P[i]%100];
			else len=D[P[i]/100][P[i]%100];
			if(len!=S[i].size()) ng++;
		}
		if(ng) continue;
		string B2[20];
		FOR(y,M) B2[y]=B[y];
		FOR(i,N) {
			r=P[i]/10000;
			y=(P[i]%10000)/100;
			x=P[i]%100;
			int len;
			if(r) len=R[y][x];
			else len=D[y][x];
			FOR(j,len) {
				if(B2[y][x]!='.' && B2[y][x]!=S[i][j]) ng++;
				B2[y][x]=S[i][j];
				if(r) x++;
				else y++;
			}
			if(ng) break;
		}
		if(ng==0) {
			cout<<M<<endl;
			FOR(y,M) cout<<B2[y]<<endl;
			break;
		}
		
		
	} while(next_permutation(ALL(P)));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

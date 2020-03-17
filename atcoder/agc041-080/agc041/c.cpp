#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[1010];
int nex;

string S3[]={
"aab",
"d.b",
"dcc",
};
string S5[]={
"bbddj",
"ffh.j",
"p.hnn",
"pvr..",
".vrxx",
};
string S7[]={
"bbddff.",
"ffhhj..",
"ll..j.v",
"...x.zv",
"...x.zf",
"..b.d.f",
"..b.djj",
};

char hoge(int y,int x) {
	return 'a'+(y+x)%26;
}


void add42(int y,int x,int N) {
	S[y][x%N]=S[y][(x+1)%N]=hoge(y,x%N);
	S[y+1][x%N]=S[y+1][(x+1)%N]=hoge(y+1,x%N);
	S[y][(x+2)%N]=S[y+1][(x+2)%N]=hoge(y,(x+2)%N);
	S[y][(x+3)%N]=S[y+1][(x+3)%N]=hoge(y,(x+3)%N);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) S[y]=string(N,'.');
	
	if(N==2) {
		cout<<-1<<endl;
	}
	else if(N==3) {
		FOR(y,N) cout<<S3[y]<<endl;
	}
	else {
		int cur=0;
		if(N%2==0) {
			FOR(y,N/2) {
				add42(cur,cur,N);
				add42(cur,cur+4,N);
				cur+=2;
			}
		}
		else {
			if(N%4==1) {
				FOR(y,5) FOR(x,5) S[N-5+y][N-5+x]=S5[y][x];
				i=5;
			}
			else {
				FOR(y,7) FOR(x,7) S[N-7+y][N-7+x]=S7[y][x];
				i=7;
			}
			FOR(j,(N-i)/2) {
				add42(cur,cur,N-i);
				add42(cur,cur+4,N-i);
				cur+=2;
			}
		}
		FOR(y,N) cout<<S[y]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

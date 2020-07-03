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


int H,W,K;
string S[2020];
int C[2020][2020][26];
int PL[2020][2020];
int PR[2020][2020];

int num(int y,int x,int s) {
	int num=0,i;
	FOR(i,26) if(C[y+s][x+s][i]-C[y][x+s][i]-C[y+s][x][i]+C[y][x][i]>0) {
		num++;
		if(num>K) return num;
		if(num+(26-i)<K) return num;
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			FOR(i,26) {
				C[y+1][x+1][i]=C[y][x+1][i]+C[y+1][x][i]-C[y][x][i];
				if(S[y][x]=='a'+i) C[y+1][x+1][i]++;
			}
		}
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		int L=0,R=0;
		if(y&&x) {
			L=max(0,PL[y-1][x-1]-1);
			R=max(0,PR[y-1][x-1]-1);
		}
		
		while(y+L+1<=H&&x+L+1<=W&&num(y,x,L+1)<K) L++;
		while(y+R+1<=H&&x+R+1<=W&&num(y,x,R+1)<=K) R++;
		PL[y][x]=L;
		PR[y][x]=R;
		ret+=R-L;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

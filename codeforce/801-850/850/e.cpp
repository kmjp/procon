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


string S;
int N;
const ll mo=998244353;

ll ret[3];
int from[16][4][4][4][4][802];
int to[16][4][4][4][4][802];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int a,b,c,d,mask;
	FOR(i,16) {
		from[i][0][1][2][3][400]=1;
	}
	FOR(i,N) {
		ZERO(to);
		FOR(mask,16) FOR(a,4) FOR(b,4) FOR(c,4) FOR(d,4) {
			FOR(x,802) if(from[mask][a][b][c][d][x]) {
				if(S[i]=='a'||S[i]=='?') {
					int y=x;
					if((a&1)&&((mask>>0)&1)) y++;
					if((b&1)&&((mask>>1)&1)) y++;
					if((c&1)&&((mask>>2)&1)) y++;
					if((d&1)&&((mask>>3)&1)) y++;
					int a2=(a&1)?0:(a|1);
					int b2=(b&1)?0:(b|1);
					int c2=(c&1)?0:(c|1);
					int d2=(d&1)?0:(d|1);
					(to[mask][a2][b2][c2][d2][y]+=from[mask][a][b][c][d][x])%=mo;
				}
				if(S[i]=='b'||S[i]=='?') {
					int y=x;
					if((a&2)&&((mask>>0)&1)) y--;
					if((b&2)&&((mask>>1)&1)) y--;
					if((c&2)&&((mask>>2)&1)) y--;
					if((d&2)&&((mask>>3)&1)) y--;
					int a2=(a&2)?0:(a|2);
					int b2=(b&2)?0:(b|2);
					int c2=(c&2)?0:(c|2);
					int d2=(d&2)?0:(d|2);
					(to[mask][a2][b2][c2][d2][y]+=from[mask][a][b][c][d][x])%=mo;
				}
			}
		}
		swap(from,to);
	}
	
	FOR(a,4) FOR(b,4) FOR(c,4) FOR(d,4) {
		int T[4]={a,b,c,d};
		vector<int> R={0};
		FOR(i,7) R.push_back(T[R.back()]);
		reverse(ALL(R));
		mask=1<<R[0];
		for(i=1;i<5;i++) {
			if(R[i]==R[0]) break;
			mask|=1<<R[i];
		}
		FOR(i,801) {
			if(i>400) (ret[0]+=from[mask][a][b][c][d][i])%=mo;
			if(i==400) (ret[1]+=from[mask][a][b][c][d][i])%=mo;
			if(i<400) (ret[2]+=from[mask][a][b][c][d][i])%=mo;
		}
	}
	
	FOR(i,3) cout<<ret[i]%mo<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

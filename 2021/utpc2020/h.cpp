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
int R[2020][2];
int C[2020][2];
int NH,NW;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			R[y][S[y][x]=='#']++;
			C[x][S[y][x]=='#']++;
		}
	}
	int num=0;
	queue<int> Q;
	FOR(y,H) if(R[y][0]==0||R[y][1]==0) Q.push(y), R[y][0]=R[y][1]=100000;
	FOR(x,W) if(C[x][0]==0||C[x][1]==0) Q.push(10000+x), C[x][0]=C[x][1]=100000;
	NH=H;
	NW=W;
	
	while(Q.size()) {
		i=Q.front();
		Q.pop();
		
		if(i<10000) {
			y=i;
			if(NH==1) continue;
			NH--;
			num++;
			
			FOR(x,W) {
				if(S[y][x]=='.') {
					if(--C[x][0]==0) C[x][0]=C[x][1]=100000,Q.push(x+10000);
				}
				if(S[y][x]=='#') {
					if(--C[x][1]==0) C[x][0]=C[x][1]=100000,Q.push(x+10000);
				}
				S[y][x]='@';
			}
		}
		else {
			x=i-10000;
			if(NW==1) continue;
			NW--;
			num++;
			
			FOR(y,H) {
				if(S[y][x]=='.') {
					if(--R[y][0]==0) R[y][0]=R[y][1]=100000,Q.push(y);
				}
				if(S[y][x]=='#') {
					if(--R[y][1]==0) R[y][0]=R[y][1]=100000,Q.push(y);
				}
				S[y][x]='@';
			}
		}
	}
	
	if(NH==1||NW==1) num++;
	
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

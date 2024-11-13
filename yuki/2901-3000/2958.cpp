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

int T,H,W;
int A[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int nex=1;
		if(H*W%8||H==1||W==1) {
			cout<<-1<<endl;
			continue;
		}
		
		if(H%4==0&&W%2==0) {
			
			FOR(y,H/4) FOR(x,W/2) {
				A[y*4][x*2]=nex;
				A[y*4][x*2+1]=nex;
				A[y*4+1][x*2]=nex;
				A[y*4+2][x*2]=nex;
				nex++;
				A[y*4+1][x*2+1]=nex;
				A[y*4+2][x*2+1]=nex;
				A[y*4+3][x*2]=nex;
				A[y*4+3][x*2+1]=nex;
				nex++;
			}
		}
		else if(W%4==0&&H%2==0) {
			swap(H,W);
			FOR(y,H/4) FOR(x,W/2) {
				A[y*4][x*2]=nex;
				A[y*4][x*2+1]=nex;
				A[y*4+1][x*2]=nex;
				A[y*4+2][x*2]=nex;
				nex++;
				A[y*4+1][x*2+1]=nex;
				A[y*4+2][x*2+1]=nex;
				A[y*4+3][x*2]=nex;
				A[y*4+3][x*2+1]=nex;
				nex++;
			}
			swap(H,W);
			FOR(y,500) FOR(x,500) if(y<x) swap(A[y][x],A[x][y]);
		}
		else if(H%8==0&&W%2) {
			FOR(y,H/8) {
				A[y*8][0]=A[y*8][1]=A[y*8][2]=A[y*8+1][2]=nex++;
				A[y*8+1][0]=A[y*8+1][1]=A[y*8+2][0]=A[y*8+3][0]=nex++;
				A[y*8+2][1]=A[y*8+2][2]=A[y*8+3][2]=A[y*8+4][2]=nex++;
				A[y*8+3][1]=A[y*8+4][1]=A[y*8+5][1]=A[y*8+5][2]=nex++;
				A[y*8+4][0]=A[y*8+5][0]=A[y*8+6][0]=A[y*8+6][1]=nex++;
				A[y*8+6][2]=A[y*8+7][0]=A[y*8+7][1]=A[y*8+7][2]=nex++;
			}
			FOR(y,H/4) for(x=3;x<W;x+=2) {
				A[y*4][x]=nex;
				A[y*4][x+1]=nex;
				A[y*4+1][x]=nex;
				A[y*4+2][x]=nex;
				nex++;
				A[y*4+1][x+1]=nex;
				A[y*4+2][x+1]=nex;
				A[y*4+3][x]=nex;
				A[y*4+3][x+1]=nex;
				nex++;
			}
			
		}
		else if(W%8==0&&H%2) {
			swap(H,W);
			FOR(y,H/8) {
				A[y*8][0]=A[y*8][1]=A[y*8][2]=A[y*8+1][2]=nex++;
				A[y*8+1][0]=A[y*8+1][1]=A[y*8+2][0]=A[y*8+3][0]=nex++;
				A[y*8+2][1]=A[y*8+2][2]=A[y*8+3][2]=A[y*8+4][2]=nex++;
				A[y*8+3][1]=A[y*8+4][1]=A[y*8+5][1]=A[y*8+5][2]=nex++;
				A[y*8+4][0]=A[y*8+5][0]=A[y*8+6][0]=A[y*8+6][1]=nex++;
				A[y*8+6][2]=A[y*8+7][0]=A[y*8+7][1]=A[y*8+7][2]=nex++;
			}
			FOR(y,H/4) for(x=3;x<W;x+=2) {
				A[y*4][x]=nex;
				A[y*4][x+1]=nex;
				A[y*4+1][x]=nex;
				A[y*4+2][x]=nex;
				nex++;
				A[y*4+1][x+1]=nex;
				A[y*4+2][x+1]=nex;
				A[y*4+3][x]=nex;
				A[y*4+3][x+1]=nex;
				nex++;
			}
			swap(H,W);
			FOR(y,500) FOR(x,500) if(y<x) swap(A[y][x],A[x][y]);
		}
		cout<<H*W/4<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

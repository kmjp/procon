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
string S[1010];
int D[1010][1010];
int Da[1010][1010];
int Dx[1010][1010];
int Db[1010][1010];
int Dy[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		int ty,tx;
		int numb=0;
		int space=0;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='V') {
				S[y][x]='.';
				ty=y;
				tx=x;
			}
			if(S[y][x]=='.') space++;
			D[y][x]=1<<25;
			Da[y][x]=1<<25;
			Dx[y][x]=1<<25;
			Db[y][x]=1<<25;
			Dy[y][x]=1<<25;
		}
		
		D[ty][tx]=0;
		queue<int> Q;
		Q.push(ty*1000+tx);
		int type=0,mi=1<<25;
		int d[]={0,1,0,-1};
		while(Q.size()) {
			y=Q.front()/1000;
			x=Q.front()%1000;
			Q.pop();
			if((y==0||y==H-1||x==0||x==W-1)) {
				type++;
				if(y!=ty||x!=tx) mi=min(mi,D[y][x]);
			}
			FOR(i,4) {
				int ty=y+d[i];
				int tx=x+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
				if(D[ty][tx]==1<<25) {
					D[ty][tx]=D[y][x]+1;
					Q.push(ty*1000+tx);
				}
			}
		}
		FOR(y,H) FOR(x,W) {
			if((y==0||y==H-1||x==0||x==W-1)&&S[y][x]=='.') {
				Da[y][x]=0;
				Dx[y][x]=y*W+x;
				Q.push(y*1000+x);
			}
		}
		while(Q.size()) {
			y=Q.front()/1000;
			x=Q.front()%1000;
			Q.pop();
			FOR(i,4) {
				int ty=y+d[i];
				int tx=x+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
				if(Da[ty][tx]>Da[y][x]+1&&Dy[ty][tx]!=Dx[y][x]) {
					Da[ty][tx]=Da[y][x]+1;
					Dx[ty][tx]=Dx[y][x];
					Q.push(ty*1000+tx);
				}
				if(Da[ty][tx]>Db[y][x]+1&&Dy[ty][tx]!=Dy[y][x]) {
					Da[ty][tx]=Db[y][x]+1;
					Dx[ty][tx]=Dy[y][x];
					Q.push(ty*1000+tx);
				}
				if(Db[ty][tx]>Da[y][x]+1&&Dx[ty][tx]!=Dx[y][x]) {
					Db[ty][tx]=Da[y][x]+1;
					Dy[ty][tx]=Dx[y][x];
					Q.push(ty*1000+tx);
				}
				if(Db[ty][tx]>Db[y][x]+1&&Dx[ty][tx]!=Dy[y][x]) {
					Db[ty][tx]=Db[y][x]+1;
					Dy[ty][tx]=Dy[y][x];
					Q.push(ty*1000+tx);
				}
			}
		}
		
		int ret=0;
		if(type==0) {
			ret=space-1;
		}
		else if(type==1) {
			if((ty==0||ty==H-1||tx==0||tx==W-1)) mi=0;
			ret=space-(mi+1);
		}
		else if(ty==0||ty==H-1||tx==0||tx==W-1){
			ret=space-(mi+1);
		}
		else {
			
			ret=-1<<20;
			FOR(y,H) FOR(x,W) if(D[y][x]<1<<20) {
				if(y==0||y==H-1){
					if(S[y][x-1]=='.'||S[y][x+1]=='.') {
						ret=max(ret,space-(D[y][x]+2));
					}
				}
				else if(x==0||x==W-1){
					if(S[y-1][x]=='.'||S[y+1][x]=='.') {
						ret=max(ret,space-(D[y][x]+2));
					}
				}
				else {
					ret=max(ret,space-(D[y][x]+1)-Da[y][x]-Db[y][x]);
				}
			}
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

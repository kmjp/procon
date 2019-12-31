#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[51];
int D[3][51][51];
int X[3],Y[3];

int memo[51][51][51][51];

int okok(int x1,int y1,int x2,int y2) {
	if(D[1][y1][x1]==0&&D[2][y2][x2]==0) return 0;
	int& ret= memo[x1][y1][x2][y2];
	
	int i;
	if(ret!=-2) return ret;
	ret = -1;
	
	int turn=(D[0][y1][x1]!=D[0][y2][x2]);
	if(D[1][y1][x1]==0) turn=1;
	if(D[2][y2][x2]==0) turn=0;
	
	FOR(i,4) {
		int dd[4]={0,1,0,-1};
		int tx,ty;
		if(turn==0) {
			tx=x1+dd[i];
			ty=y1+dd[i^1];
			if(tx<0|| ty<0||tx>=W||ty>=H) continue;
			if(tx==x2&&ty==y2) continue;
			if(D[1][ty][tx]!=D[1][y1][x1]-1) continue;
			if(okok(tx,ty,x2,y2)>=0) return ret=i;
		}
		else {
			tx=x2+dd[i];
			ty=y2+dd[i^1];
			if(tx<0|| ty<0||tx>=W||ty>=H) continue;
			if(tx==x1&&ty==y1) continue;
			if(D[2][ty][tx]!=D[2][y2][x2]-1) continue;
			if(okok(x1,y1,tx,ty)>=0) return ret=i;
		}
	}
	
	return ret;
}

void fix(int x1,int y1,int x2,int y2) {
	int turn=0;
	int& ret= memo[x1][y1][x2][y2];
	
	if(D[1][y1][x1]==0&&D[2][y2][x2]==0) return;
	
	turn=(D[0][y1][x1]!=D[0][y2][x2]);
	if(D[1][y1][x1]==0) turn=1;
	if(D[2][y2][x2]==0) turn=0;
	
	int dd[4]={0,1,0,-1};
	if(turn==0 && S[y1][x1]=='.') S[y1][x1]='a';
	if(turn==1 && S[y2][x2]=='.') S[y2][x2]='b';
	if(turn==0) fix(x1+dd[ret],y1+dd[ret^1],x2,y2);
	if(turn==1) fix(x1,y1,x2+dd[ret],y2+dd[ret^1]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	memset(D,0x3f,sizeof(D));
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') X[0]=x, Y[0]=y, D[0][y][x]=0, Q.push(0+y*100+x);
			if(S[y][x]=='A') X[1]=x, Y[1]=y, D[1][y][x]=0, Q.push(10000+y*100+x);
			if(S[y][x]=='B') X[2]=x, Y[2]=y, D[2][y][x]=0, Q.push(20000+y*100+x);
		}
	}
	
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		int st=k/10000, cy=k/100%100, cx=k%100;
		FOR(i,4) {
			int dd[4]={0,1,0,-1};
			int tx=cx+dd[i],ty=cy+dd[i^1];
			if(tx<0 || ty<0 || tx>=W || ty>=H) continue;
			if(S[ty][tx]=='#') continue;
			if(D[st][ty][tx]<=D[st][cy][cx]+1) continue;
			D[st][ty][tx]=D[st][cy][cx]+1;
			Q.push(st*10000+ty*100+tx);
		}
	}
	
	FOR(y,51) FOR(x,51) FOR(i,51) FOR(j,51) memo[y][x][i][j]=-2;
	
	if(okok(X[0],Y[0],X[0],Y[0])<0) {
		cout<<"NA"<<endl;
	}
	else {
		fix(X[0],Y[0],X[0],Y[0]);
		FOR(y,H) cout<<S[y]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

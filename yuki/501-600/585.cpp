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

string S[4];
int A[4][4];
int PY[16];
int PX[16];
vector<vector<int>> R;

void goswap(int y1,int x1,int y2,int x2) {
	y1=(y1+8)%4;
	x1=(x1+8)%4;
	y2=(y2+8)%4;
	x2=(x2+8)%4;
	swap(A[y1][x1],A[y2][x2]);
	PY[A[y1][x1]]=y1;
	PX[A[y1][x1]]=x1;
	PY[A[y2][x2]]=y2;
	PX[A[y2][x2]]=x2;
}


void rotR(int row,int num) {
	num=(num+8)%4;
	if(num==0) return;
	R.push_back({0,row,num});
	int i;
	FOR(i,num) {
		goswap(row,3,row,2);
		goswap(row,2,row,1);
		goswap(row,1,row,0);
	}
}

void rotD(int col,int num) {
	num=(num+8)%4;
	if(num==0) return;
	R.push_back({1,col,num});
	int i;
	FOR(i,num) {
		goswap(3,col,2,col);
		goswap(2,col,1,col);
		goswap(1,col,0,col);
	}
}

void swapadj(int x) {
	rotD(x-1,1);
	rotR(3,-1);
	rotD(x-1,-1);
	rotR(3,2);
	rotD(x-1,1);
	rotR(3,-1);
	rotD(x-1,-1);
	rotR(3,-1);
}

void test() {
	int y,x;
	FOR(y,4) {
		FOR(x,4) _P("%c",'A'+A[y][x]);
		_P("\n");
	}
	_P("::\n");
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,4) {
		cin>>S[y];
		FOR(x,4) {
			A[y][x]=S[y][x]-'A';
			PY[A[y][x]]=y;
			PX[A[y][x]]=x;
		}
	}
	FOR(x,4) {
		FOR(y,3) {
			int target=y*4+x;
			int py=PY[target], px=PX[target];
			
			if(y==0) {
				if(PX[target]!=x) {
					rotD(px,3-py);
					rotR(3,x-px);
					rotD(px,-(3-py));
				}
				rotD(x,4-PY[target]);
			}
			else {
				if(PX[target]!=x) {
					rotD(x,3-y);
					rotD(px,3-py);
					rotR(3,x-px);
					rotD(px,-(3-py));
					rotD(x,-(3-y));
				}
				else {
					if(PY[target]==y) continue;
					rotD(x,3-py);
					rotR(3,1);
					rotD(x,(3-y)-(3-py));
					rotR(3,3);
					rotD(x,-(3-y));
				}
			}
		}
	}
	
	rotR(3,4-PX[12]);
	if(PX[13]==3) swapadj(2);
	if(PX[13]==2) swapadj(1);
	if(PX[14]==3) swapadj(2);
	
	_P("%d\n",R.size());
	FORR(r,R) {
		if(r[0]==0) _P("R");
		else _P("C");
		_P(" %d %d\n",r[1],r[2]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
int A[202][202];
int CH,CW,swapped=0;

void addV(vector<vector<int>>& R,int y1,int y2,int x,int v) {
	int y;
	for(y=y1;y<=y2;y++) R[y][x]=v;
}
void addH(vector<vector<int>>& R,int y,int x1,int x2,int v) {
	int x;
	for(x=x1;x<=x2;x++) R[y][x]=v;
}

vector<vector<int>> rotate(vector<vector<int>> A) {
	int y,x;
	if(A.empty()) return A;
	int H=A[0].size();
	int W=A.size();
	vector<vector<int>> R(H);
	FOR(y,H) {
		R[y].resize(W);
		FOR(x,W) R[y][x]=A[x][y];
	}
	return R;
}


void out(vector<vector<int>> A) {
	if(A.empty()) {
		cout<<-1<<endl;
	}
	else  {
		int y,x;
		int ma=0;
		FOR(y,A.size()) FOR(x,A[y].size()) ma=max(ma,A[y][x]);
		cout<<ma<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
			cout<<endl;
		}
	}
}

vector<vector<int>> testC(int H,int W) {
	int i,j,k,l,r,x,y; string s;
	vector<vector<int>> R(H);
	R.resize(H);
	FOR(y,H) R[y].resize(W);
	
	if(H>W) {
		return rotate(testC(W,H));
	}
	
	if(H==2) {
		return {};
	}
	else if(H==3) {
		if(W%2) return {};
		int nex=2;
		R[0][0]=R[0][1]=R[0][2]=1;
		R[1][0]=R[1][2]=1;
		R[2][0]=1;
		
		for(i=1;i<H*W/6-1;i++) {
			R[1][(i-1)*2+1]=R[1][(i-1)*2+4]=i+1;
			if(i%2) {
				R[2][(i-1)*2+1]=R[2][(i-1)*2+2]=R[2][(i-1)*2+3]=R[2][(i-1)*2+4]=i+1;
			}
			else {
				R[0][(i-1)*2+1]=R[0][(i-1)*2+2]=R[0][(i-1)*2+3]=R[0][(i-1)*2+4]=i+1;
			}
		}
		R[0][W-1]=R[1][W-1]=R[2][W-1]=R[1][W-3]=H*W/6;
		if(H*W/6%2) {
			R[0][W-2]=R[0][W-3]=H*W/6;
		}
		else {
			R[2][W-2]=R[2][W-3]=H*W/6;
		}
	}
	else if(H==4) {
		R[0][0]=R[0][W-1]=R[1][W-1]=R[2][W-1]=1;
		R[1][0]=R[2][0]=R[3][0]=R[3][W-1]=2;
		for(x=1;x<W-1;x++) {
			R[0][x]=R[2][x]=1;
			R[1][x]=R[3][x]=2;
		}
	}
	else {
		auto V=testC(H-1,W-2);
		if(V.size()) {
			int ma=0;
			FOR(y,H-1) FOR(x,W-2) {
				ma=max(ma,V[y][x]);
				R[y][x+1]=V[y][x];
			}
			FOR(y,H) R[y][0]=R[y][W-1]=ma+1;
			FOR(x,W) R[H-1][x]=ma+1;
			return R;
		}
		V=testC(H-2,W-1);
		if(V.size()) {
			int ma=0;
			FOR(y,H-2) FOR(x,W-1) {
				ma=max(ma,V[y][x]);
				R[y+1][x]=V[y][x];
			}
			FOR(y,H) R[y][W-1]=ma+1;
			FOR(x,W) R[0][x]=R[H-1][x]=ma+1;
			return R;
		}
		return {};
	}
	return R;
	
	
	
	
}

vector<vector<int>> testT(int H,int W) {
	int i,j,k,l,r,x,y; string s;
	vector<vector<int>> R(H);
	R.resize(H);
	FOR(y,H) R[y].resize(W);
	
	if(H>W) {
		return rotate(testT(W,H));
	}
	
	if(H==2) return {};
	if(H==3) {
		if(W<6) return {};
		R[0][0]=R[1][0]=R[2][0]=R[1][1]=1;
		R[1][2]=2;
		R[1][3]=3;
		for(x=1;x<W;x++) {
			R[0][x]=2;
			R[2][x]=3;
		}
		for(x=4;x<W;x++) R[1][x]=4;
		R[0][W-1]=R[1][W-1]=R[2][W-1]=4;
	}
	else if(H==4) {
		addV(R,0,H-2,0,1);
		addH(R,1,1,W-2,1);
		addH(R,0,1,W-1,2);
		R[1][W-2]=2;
		addH(R,2,2,W-1,3);
		addV(R,1,H-1,W-1,3);
		addH(R,H-1,0,W-2,4);
		R[H-2][1]=4;
	}
	else if(H==5) {
		addV(R,0,H-2,0,1);
		addH(R,1,1,W-3,1);
		addH(R,0,1,W-1,2);
		R[1][W-2]=2;
		addH(R,2,1,W-2,3);
		R[3][2]=3;
		addV(R,1,H-1,W-1,4);
		addH(R,H-2,3,W-2,4);
		R[H-2][1]=5;
		addH(R,H-1,0,W-2,5);
		
	}
	else {
		auto V=testT(H-2,W-2);
		int ma=0;
		FOR(y,H-2) FOR(x,W-2) {
			ma=max(ma,V[y][x]);
			R[y+2][x+1]=V[y][x];
		}
		FOR(y,H) {
			R[y][0]=ma+1;
			R[y][W-1]=ma+3;
		}
		R[1][1]=ma+1;
		R[1][2]=ma+2;
		for(x=1;x<W-1;x++) R[0][x]=ma+2;
		for(x=3;x<W-1;x++) R[1][x]=ma+3;
	}
	return R;
}
vector<vector<int>> testCT(int H,int W) {
	int i,j,k,l,r,x,y; string s;
	vector<vector<int>> R(H);
	R.resize(H);
	FOR(y,H) R[y].resize(W);
	
	if(H>W) {
		return rotate(testCT(W,H));
	}
	
	if(H==2) return {};
	if(H==3) {
		addH(R,0,0,W-2,1);
		addH(R,2,0,W-2,1);
		R[1][0]=1;
		addH(R,1,1,W-1,2);
		R[0][W-1]=R[2][W-1]=2;
	}
	else if(H==4) {
		addH(R,0,0,W-1,1);
		R[1][W-2]=1;
		addH(R,1,0,W-3,2);
		addH(R,3,0,W-2,2);
		R[2][0]=2;
		
		addH(R,2,1,W-1,3);
		R[1][W-1]=R[3][W-1]=3;
	}
	else {
		auto V=testCT(H-2,W-2);
		int ma=0;
		FOR(y,H-2) FOR(x,W-2) {
			ma=max(ma,V[y][x]);
			R[y+2][x+1]=V[y][x];
		}
		FOR(y,H) {
			R[y][0]=ma+1;
			R[y][W-1]=ma+3;
		}
		R[1][1]=ma+1;
		R[1][2]=ma+2;
		for(x=1;x<W-1;x++) R[0][x]=ma+2;
		for(x=3;x<W-1;x++) R[1][x]=ma+3;
	}
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	ZERO(A);
	out(testC(H,W));
	ZERO(A);
	out(testT(H,W));
	ZERO(A);
	out(testCT(H,W));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

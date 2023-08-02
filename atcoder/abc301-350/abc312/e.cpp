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

int N;
int X[2][101010],Y[2][101010],Z[2][101010];

int ZXY[101][101][101];
int XYZ[101][101][101];
int YXZ[101][101][101];
int ret[202020];


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	MINUS(ZXY);
	MINUS(XYZ);
	MINUS(YXZ);
	
	cin>>N;
	
	FOR(i,N) {
		cin>>X[0][i]>>Y[0][i]>>Z[0][i]>>X[1][i]>>Y[1][i]>>Z[1][i];
		
		set<int> C;
		for(x=X[0][i];x<=X[1][i];x+=X[1][i]-X[0][i]) {
			for(y=Y[0][i];y<Y[1][i];y++) {
				for(z=Z[0][i];z<Z[1][i];z++) {
					if(XYZ[x][y][z]>=0) {
						C.insert(XYZ[x][y][z]);
						XYZ[x][y][z]=-1;
					}
					else {
						XYZ[x][y][z]=i;
					}
				}
			}
		}
		for(x=Y[0][i];x<=Y[1][i];x+=Y[1][i]-Y[0][i]) {
			for(y=X[0][i];y<X[1][i];y++) {
				for(z=Z[0][i];z<Z[1][i];z++) {
					if(YXZ[x][y][z]>=0) {
						C.insert(YXZ[x][y][z]);
						YXZ[x][y][z]=-1;
					}
					else {
						YXZ[x][y][z]=i;
					}
				}
			}
		}
		for(x=Z[0][i];x<=Z[1][i];x+=Z[1][i]-Z[0][i]) {
			for(y=X[0][i];y<X[1][i];y++) {
				for(z=Y[0][i];z<Y[1][i];z++) {
					if(ZXY[x][y][z]>=0) {
						C.insert(ZXY[x][y][z]);
						ZXY[x][y][z]=-1;
					}
					else {
						ZXY[x][y][z]=i;
					}
				}
			}
		}
		
		
		
		FORR(c,C) {
			ret[c]++;
			ret[i]++;
		}
		
	}
	FOR(i,N) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

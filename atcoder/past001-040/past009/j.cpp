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

int N,Q;
int T[202020],X[202020],Y[202020];
int TX[4],TY[4];
int R[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	TY[1]=N-1;
	TX[2]=N-1;
	TX[3]=TY[3]=N-1;
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>Y[i]>>X[i];
			X[i]--,Y[i]--;
			if(N==1) {
				x=y=0;
			}
			else {
				x=TX[0]+Y[i]*(TX[1]-TX[0])/(N-1)+X[i]*(TX[2]-TX[0])/(N-1);
				y=TY[0]+Y[i]*(TY[1]-TY[0])/(N-1)+X[i]*(TY[2]-TY[0])/(N-1);
			}
			R[y][x]^=1;
		}
		else if(T[i]==2) {
			cin>>s;
			if(s=="A") {
				swap(TX[0],TX[1]);
				swap(TX[1],TX[3]);
				swap(TX[3],TX[2]);
				swap(TY[0],TY[1]);
				swap(TY[1],TY[3]);
				swap(TY[3],TY[2]);
			}
			else {
				swap(TX[0],TX[2]);
				swap(TX[2],TX[3]);
				swap(TX[3],TX[1]);
				swap(TY[0],TY[2]);
				swap(TY[2],TY[3]);
				swap(TY[3],TY[1]);
			}
		}
		else {
			cin>>s;
			if(s=="A") {
				swap(TY[0],TY[1]);
				swap(TX[0],TX[1]);
				swap(TY[2],TY[3]);
				swap(TX[2],TX[3]);
			}
			else {
				swap(TY[0],TY[2]);
				swap(TX[0],TX[2]);
				swap(TY[1],TY[3]);
				swap(TX[1],TX[3]);
			}
		}
	}
	FOR(y,N) {
		FOR(x,N) {
			int ty=0,tx=0;
			if(N>=2) {
				tx=TX[0]+y*(TX[1]-TX[0])/(N-1)+x*(TX[2]-TX[0])/(N-1);
				ty=TY[0]+y*(TY[1]-TY[0])/(N-1)+x*(TY[2]-TY[0])/(N-1);
			}
			cout<<R[ty][tx];
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

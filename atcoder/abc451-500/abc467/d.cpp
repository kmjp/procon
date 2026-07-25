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

int T;
ll PX,PY,QX,QY,RX,RY,SX,SY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>PX>>PY>>QX>>QY>>RX>>RY>>SX>>SY;
		ll DX1=QX-PX;
		ll DY1=QY-PY;
		ll DX2=SX-RX;
		ll DY2=SY-RY;
		
		if(DX1*DY2-DX2*DY1) {
			cout<<"Yes"<<endl;
			continue;
		}
		swap(DX1,DY1);
		DY1=-DY1;
		if(DX1==0) {
			if(PX+QX==RX+SX) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			continue;
		}
		__int128 Y1P=(PY+QY)*DX1-DY1*(PX+QX);
		__int128 Y2P=(RY+SY)*DX1-DY1*(RX+SX);
		if(Y1P==Y2P) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

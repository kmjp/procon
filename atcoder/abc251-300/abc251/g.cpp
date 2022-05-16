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

int N,M,Q;
ll X[202020],Y[202020];
ll CX[202020],CY[202020];
ll DX[202020],DY[202020];
ll U,V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,N) {
		DX[i]=X[(i+1)%N]-X[i];
		DY[i]=Y[(i+1)%N]-Y[i];
	}
	
	cin>>M;
	FOR(i,M) {
		cin>>U>>V;
		if(i==0) {
			FOR(j,N) {
				CX[j]=U;
				CY[j]=V;
			}
		}
		else {
			FOR(j,N) {
				if((U-CX[j])*DY[j]-(V-CY[j])*DX[j]<0) {
					CX[j]=U;
					CY[j]=V;
				}
			}
		}
	}
	FOR(i,N) X[i]+=CX[i],Y[i]+=CY[i];
	
	
	cin>>Q;
	while(Q--) {
		ll TX,TY;
		cin>>TX>>TY;
		FOR(i,N) {
			if((TX-X[i])*DY[i]-(TY-Y[i])*DX[i]>0) break;
		}
		if(i==N) {
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

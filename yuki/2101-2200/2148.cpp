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
int N;
int C[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) FOR(j,3) C[j][i]=0;
		int D[3]={};
		FOR(i,N) {
			cin>>s>>x;
			if(s=="R") C[0][x-1]++,D[0]++;
			if(s=="G") C[1][x-1]++,D[1]++;
			if(s=="B") C[2][x-1]++,D[2]++;
		}
		
		if(D[0]==N||D[1]==N||D[2]==N) {
			cout<<"YES"<<endl;
		}
		else if(D[0]==0||D[1]==0||D[2]==0) {
			FOR(i,N) if(C[0][i]+C[1][i]+C[2][i]==2) break;
			if(i==N) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
			}
		}
		else {
			int X[4]={};
			FOR(i,N) {
				if(C[0][i]&&C[1][i]&&C[2][i]) X[3]++;
				if(C[0][i]==0&&C[1][i]&&C[2][i]) X[0]=1;
				if(C[1][i]==0&&C[0][i]&&C[2][i]) X[1]=1;
				if(C[2][i]==0&&C[0][i]&&C[1][i]) X[2]=1;
			}
			if(X[0]+X[1]+X[2]+X[3]>=2) {
				cout<<"YES"<<endl;
			}
			else if(X[3]==1&&(D[0]==1||D[1]==1||D[2]==1)) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

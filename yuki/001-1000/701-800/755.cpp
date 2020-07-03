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

int N,M;
int A[150][150];
ll S[150][150];

int X[10],Y[10];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,M) {
		FOR(x,M) {
			cin>>A[y][x];
			S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
		}
	}
	FOR(i,N) {
		cin>>Y[i]>>X[i];
		Y[i]--,X[i]--;
		int ret=0;
		for(int y1=0;y1<=Y[i];y1++) {
			for(int x1=0;x1<=X[i];x1++) {
				for(int y2=Y[i];y2<M;y2++) {
					for(int x2=X[i];x2<M;x2++) {
						ll sum=S[y2+1][x2+1]-S[y2+1][x1]-S[y1][x2+1]+S[y1][x1];
						ret+=sum==0;
					}
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

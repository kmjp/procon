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
int from[1515][1515];
int to[1515][1515];
int A[101],B[101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int S[3]={};
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]--;
		S[A[i]]+=B[i];
	}
	FOR(x,1515) FOR(y,1515) from[x][y]=1010;
	from[S[0]][S[1]]=0;
	FOR(i,N) {
		FOR(x,1515) FOR(y,1515) to[x][y]=1010;
		FOR(x,1515) FOR(y,1515) if(from[x][y]<100) {
			int lef=S[0]+S[1]+S[2]-x-y;
			to[x][y]=min(to[x][y],from[x][y]);
			if(A[i]==0&&x>=B[i]) {
				if(y+B[i]<=1500) to[x-B[i]][y+B[i]]=min(to[x-B[i]][y+B[i]],from[x][y]+1);
				if(lef+B[i]<=1500) to[x-B[i]][y]=min(to[x-B[i]][y],from[x][y]+1);
			}
			if(A[i]==1&&y>=B[i]) {
				if(x+B[i]<=1500) to[x+B[i]][y-B[i]]=min(to[x+B[i]][y-B[i]],from[x][y]+1);
				if(lef+B[i]<=1500) to[x][y-B[i]]=min(to[x][y-B[i]],from[x][y]+1);
			}
			if(A[i]==2&&lef>=B[i]) {
				if(x+B[i]<=1500) to[x+B[i]][y]=min(to[x+B[i]][y],from[x][y]+1);
				if(y+B[i]<=1500) to[x][y+B[i]]=min(to[x][y+B[i]],from[x][y]+1);
			}
		}
		swap(from,to);
	}
	if((S[0]+S[1]+S[2])%3) {
		cout<<"-1"<<endl;
	}
	else {
		x=(S[0]+S[1]+S[2])/3;
		if(from[x][x]>100) {
			cout<<-1<<endl;
		}
		else {
			cout<<from[x][x]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

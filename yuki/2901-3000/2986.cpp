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

int N,K;
int A[6][10][10];
int B[10][10];
int step[10];

void move(int r,int s) {
	int y,x;
	if(r<N) {
		FOR(y,N) FOR(x,N) A[s+1][A[s][r][y]][x]=A[s][y][x];
	}
	else {
		int c=r-N;
		FOR(y,N) FOR(x,N) A[s+1][y][A[s][x][c]]=A[s][y][x];
	}
}

void dfs(int cur) {
	int y,x,i;
	if(cur==K) {
		int ok=1;
		FOR(y,N) FOR(x,N) if(A[cur][y][x]!=B[y][x]) ok=0;
		if(ok) {
			vector<int> ret;
			while(cur) {
				if(step[cur-1]<N) {
					int tar=A[cur-1][step[cur-1]][0];
					while(1) {
						int ok=1;
						FOR(y,N) FOR(x,N) if(A[cur-1][y][x]!=A[cur][y][x]) ok=0;
						if(ok) {
							cur--;
							break;
						}
						FOR(y,N) if(A[cur][y][0]==tar) break;
						move(y,cur);
						ret.push_back(y);
						FOR(y,N) FOR(x,N) A[cur][y][x]=A[cur+1][y][x];
					}
				}
				else {
					int tar=A[cur-1][0][step[cur-1]-N];
					while(1) {
						int ok=1;
						FOR(y,N) FOR(x,N) if(A[cur-1][y][x]!=A[cur][y][x]) ok=0;
						if(ok) {
							cur--;
							break;
						}
						FOR(x,N) if(A[cur][0][x]==tar) break;
						move(x+N,cur);
						ret.push_back(x+N);
						FOR(y,N) FOR(x,N) A[cur][y][x]=A[cur+1][y][x];
					}
				}
			}
			cout<<ret.size()<<endl;
			FORR(r,ret) {
				if(r<N) cout<<"R "<<r+1<<endl;
				else cout<<"C "<<(r+1)-N<<endl;
			}
			exit(0);
		}
		return;
	}
	FOR(i,2*N) {
		move(i,cur);
		step[cur]=i;
		dfs(cur+1);
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) {
		cin>>A[0][y][x];
		A[0][y][x]--;
	}
	FOR(y,N) FOR(x,N) {
		cin>>B[y][x];
		B[y][x]--;
	}
	dfs(0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

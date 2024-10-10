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


int N,M;
int E[4][4];
int V[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x][y]=E[y][x]=1;
	}
	cin>>V[0]>>V[1]>>V[2];
	sort(V,V+3);
	if(V[0]==V[1]||V[1]==V[2]) {
		if(N==3&&M==3) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	if(N==4) {
		vector<int> A={0,1,2,3};
		do {
			if(E[A[0]][A[1]]&&E[A[1]][A[2]]&&E[A[2]][A[3]]&&E[A[3]][A[0]]) {
				cout<<"Yes"<<endl;
				return;
			}
			if(E[A[0]][A[1]]&&E[A[1]][A[2]]&&E[A[2]][A[0]]) {
				if(V[0]==V[1]||V[1]==V[2]) {
					cout<<"Yes"<<endl;
					return;
				}
				else if(V[0]+V[1]+V[2]!=A[0]+A[1]+A[2]) {
					cout<<"Yes"<<endl;
					return;
				}
			}
		} while(next_permutation(ALL(A)));
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

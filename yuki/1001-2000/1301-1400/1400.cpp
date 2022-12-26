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
ll T;
string S;
bitset<2040> E[2020];
int D[2020][2020][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(y,N) {
		cin>>S;
		FOR(x,N) {
			E[y][x]=S[x]=='1';
			D[y][x][0]=D[y][x][1]=101010;
		}
	}
	
	
	FOR(i,N) {
		bitset<2040> B[2],nex[2];
		nex[0][i]=1;
		FOR(j,2*N+1) {
			bitset<2040> diff=B[j&1]^nex[j&1];
			while(diff._Find_first()<N) {
				x=diff._Find_first();
				diff[x]=diff[x]^1;
				B[j&1][x]=1;
				D[i][x][j&1]=j;
				nex[(j&1)^1] |= E[x];
			}
		}
	}
	
	FOR(y,N) FOR(x,N) {
		if(D[y][x][T%2]>T) return _P("No\n");
		if(D[y][x][T%2]==101010) return _P("No\n");
	}
	cout<<"Yes"<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

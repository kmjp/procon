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
string S,T;

vector<int> P[2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	
	FOR(i,N+M) {
		P[0][S[i]-'0'].push_back(i);
	}
	FOR(i,N+M) {
		P[1][T[i]-'0'].push_back(i);
	}
	
	int ma=0;
	FOR(i,2) {
		if(P[0][i].empty()) continue;
		if(P[0][i][0]&&P[1][i][0]) continue;
		int C[2]={0,0};
		int cur=i;
		C[cur]=1;
		int score=0;
		string G;
		G+='0'+i;
		for(int step=1;step<N+M;step++) {
			if(P[0][cur].size()==C[cur]) {
				cur^=1;
			}
			else if(P[0][cur^1].size()==C[cur^1]) {
				score++;
			}
			else if(min(P[0][cur][C[cur]],P[1][cur][C[cur]])<=step&&max(P[0][cur^1][C[cur^1]],P[1][cur^1][C[cur^1]])>step) {
				score++;
			}
			else {
				cur^=1;
			}
			G+='0'+cur;
			C[cur]++;
		}
		ma=max(ma,score);
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

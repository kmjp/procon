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

int T,H,W;
vector<string> S;

vector<string> flip(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[x][y]=S[y][x]; //left
	return T;
}

int dp[1<<20];
int A[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		S.clear();
		FOR(y,H) {
			cin>>s;
			S.push_back(s);
		}
		
		if(H>W) {
			S=flip(S);
			swap(H,W);
		}
		
		ll ret=0;
		int y2;
		FOR(y,H) {
			FOR(x,W+1) A[x]=1<<19;
			for(int y1=y;y1<H;y1++) {
				int cur=0;
				dp[A[0]]=1;
				FOR(x,W) {
					cur+=((S[y1][x]=='#')?1:-1);
					A[x+1]+=cur;
					ret+=dp[A[x+1]]++;
				}
				FOR(x,W+1) dp[A[x]]=0;
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

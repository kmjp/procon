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

int H,W;
string S[101];
int Q,K,D;
string A;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if((y==0||S[y-1][x]=='#')&&y+1<H&&S[y+1][x]=='.') V.push_back({y+1,x+1});
		if((x==0||S[y][x-1]=='#')&&x+1<W&&S[y][x+1]=='.') V.push_back({y+1,x+1});
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	cout<<V.size()<<endl;
	FOR(i,V.size()) {
		y=V[i].first-1;
		x=V[i].second-1;
		int len=0;
		FOR(j,W) if(S[y][x+j]!='.'||x+j==W) break;
		if(j<=1) {
			cout<<"- ";
		}
		else {
			cout<<string(j,'a')<<" ";
		}
		FOR(j,H) if(S[y+j][x]!='.'||y+j==H) break;
		if(j<=1) {
			cout<<"- ";
		}
		else {
			cout<<string(j,'a')<<" ";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

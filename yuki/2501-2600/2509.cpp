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
int A[102][102];
vector<pair<int,int>> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y+1][x+1];
	
	int ma=0;
	vector<pair<pair<int,int>,int>> V;
	int dy[]={1,1,1,0,0,-1,-1,-1};
	int dx[]={-1,0,1,-1,1,-1,0,1};
	FOR(y,H+2) {
		V.push_back({{y,0},2});
		V.push_back({{y,0},4});
		V.push_back({{y,0},7});
		V.push_back({{y,W+1},0});
		V.push_back({{y,W+1},3});
		V.push_back({{y,W+1},5});
	}
	FOR(x,W+2) {
		V.push_back({{0,x},0});
		V.push_back({{0,x},1});
		V.push_back({{0,x},2});
		V.push_back({{H+1,x},5});
		V.push_back({{H+1,x},6});
		V.push_back({{H+1,x},7});
	}
	
	FORR2(a,i,V) FORR2(b,j,V) {
		if(a>b) continue;
		if(a==b&&i>j) continue;
		S.clear();
		int cy=a.first,cx=a.second;
		int sum=0;
		while(1) {
			cy+=dy[i];
			cx+=dx[i];
			if(cy<=0||cy>=H+1||cx<=0||cx>=W+1) break;
			sum+=A[cy][cx];
			S.push_back({cy,cx});
		}
		if(S.empty()) continue;
		cy=b.first,cx=b.second;
		while(1) {
			cy+=dy[j];
			cx+=dx[j];
			if(cy<=0||cy>=H+1||cx<=0||cx>=W+1) break;
			sum+=A[cy][cx];
			S.push_back({cy,cx});
			
		}
		if(sum<=ma) continue;
		sort(ALL(S));
		S.erase(unique(ALL(S)),S.end());
		sum=0;
		FORR2(y,x,S) sum+=A[y][x];
		ma=max(ma,sum);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

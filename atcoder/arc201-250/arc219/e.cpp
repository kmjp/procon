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
int H,W;
string S[2010];
vector<pair<int,int>> V;
vector<int> sum;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,2*H) {
			cin>>S[y];
		}
		V.clear();
		sum={0};
		FOR(x,2*W) {
			V.push_back({0,x});
			sum.push_back(sum.back()+(S[0][x]=='o'));
		}
		for(x=2*W-2;x>=0;x-=2) {
			for(y=1;y<2*H;y++) {
				V.push_back({y,x+1});
				sum.push_back(sum.back()+(S[y][x+1]=='o'));
			}
			for(y=2*H-1;y>=1;y--) {
				V.push_back({y,x});
				sum.push_back(sum.back()+(S[y][x]=='o'));
			}
		}
		
		FOR(y,2*H) FOR(x,2*W) S[y][x]='B';
		FOR(i,H*W*2) if(sum[i+2*H*W]-sum[i]==H*W) {
			FOR(j,2*H*W) S[V[i+j].first][V[i+j].second]='A';
			break;
		}
		FOR(y,2*H) cout<<S[y]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

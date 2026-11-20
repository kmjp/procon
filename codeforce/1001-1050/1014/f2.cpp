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

int T,N;
string S;

int ret[1<<20];
int seg[1<<20];

vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		V.clear();
		FOR(i,N) {
			if(V.empty()||S[i]!=S[V.back().first]) V.push_back({i,0});
			V.back().second++;
			seg[i]=i+2-V.size();
			ret[i]=0;
		}
		for(int m=2;m<=V.size();m++) {
			for(k=1;;k++) {
				if(k==1) {
					x=y=m-1;
				}
				else {
					
					if(V[x].second>=2) {
						x+=m-1;
					}
					else {
						x+=m;
					}
					y+=m;
				}
				if(x>=V.size()) break;
				y=min(y,(int)V.size()-1);
				ret[V[x].first]++;
				ret[V[y].first+V[y].second]--;
			}
		}
		int pat=0;
		FOR(i,N) {
			ret[i+1]+=ret[i];
			seg[i]+=ret[i];
			_P("%d ",seg[i]);
		}
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int T,N,D;
int X[202020],Y[202020];

vector<pair<int,int>> XpY[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>D;
		FOR(i,N) {
			cin>>X[i]>>Y[i];
		}
		vector<int> ret={0,0,0};
		FOR(j,2) {
			set<int> Sp;
			FOR(i,N) {
				XpY[X[i]+Y[i]+202020].push_back({X[i],i});
				Sp.insert(X[i]+Y[i]+202020);
			}
			FORR(a,Sp) sort(ALL(XpY[a]));
			FORR(a,Sp) {
				for(int L=0,R=0;L<XpY[a].size();L++) {
					while(R<XpY[a].size()&&XpY[a][R].first-XpY[a][L].first<D/2) R++;
					if(R==XpY[a].size()) break;
					if(XpY[a][R].first-XpY[a][L].first==D/2) {
						if(a+D<=402020&&XpY[a+D].size()) {
							x=lower_bound(ALL(XpY[a+D]),make_pair(XpY[a][R].first,0))-XpY[a+D].begin();
							if(x<XpY[a+D].size()&&Y[XpY[a+D][x].second]>=Y[XpY[a][L].second]) {
								ret={XpY[a][L].second+1,XpY[a][R].second+1,XpY[a+D][x].second+1};
							}
						}
						if(a-D>=0&&XpY[a-D].size()) {
							x=lower_bound(ALL(XpY[a-D]),make_pair(XpY[a][L].first+1,0))-XpY[a-D].begin();
							
							if(x>0&&Y[XpY[a-D][x-1].second]<=Y[XpY[a][R].second]) {
								ret={XpY[a][L].second+1,XpY[a][R].second+1,XpY[a-D][x-1].second+1};
							}
						}
						
					}
				}
			}
			FORR(a,Sp) XpY[a].clear();
			FOR(i,N) Y[i]=-Y[i];
		}
		cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
	}
		
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

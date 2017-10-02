#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K;
string A;
string S[8];
int vis[8][8];
ll ret;
vector<vector<pair<int,int>>> cand[6];
vector<pair<ll,ll>> mask[6];
vector<bitset<16000>> c2[6];
bitset<16000> bs;


void dfs(int y,int x,int step) {
	if(vis[y][x]) return;
	if(S[y][x]!=A[step-1]) return;
	if(step==K) {
		ret++;
	}
	else {
		vis[y][x]=1;
		for(int cy=max(0,y-1);cy<=min(7,y+1);cy++) {
			for(int cx=max(0,x-1);cx<=min(7,x+1);cx++) {
				dfs(cy,cx,step+1);
			}
		}
		vis[y][x]=0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>A;
	FOR(y,8) cin>>S[y];
	if(K<=9) {
		FOR(y,8) FOR(x,8) dfs(y,x,1);
	}
	else {
		cand[0].push_back(vector<pair<int,int>>({{0,0}}));
		int id=(0+5)*11+(0+5);
		mask[0].push_back({0,0});
		for(i=1;i<=5;i++) {
			FOR(j,cand[i-1].size()) {
				auto& c=cand[i-1][j];
				ll ma=mask[i-1][j].first;
				ll mb=mask[i-1][j].second;
				for(y=c.back().first-1;y<=c.back().first+1;y++) {
					for(x=c.back().second-1;x<=c.back().second+1;x++) {
						if(y==0 && x==0) continue;
						int id=(y+5)*11+(x+5);
						ll a=(id<60)?(1LL<<id):0;
						ll b=(id>=60)?(1LL<<(id-60)):0;
						
						if((ma&a)==0 && (mb&b)==0) {
							cand[i].push_back(c);
							cand[i].back().push_back({y,x});
							mask[i].push_back({ ma|a, mb|b});
						}
					}
				}
			}
			c2[i].resize(cand[i].size());
		}
		for(i=4;i<=5;i++) {
			FOR(x,cand[i].size()) {
				FOR(j,cand[5].size()) {
					if(mask[i][x].first&mask[5][j].first) continue;
					if(mask[i][x].second&mask[5][j].second) continue;
					c2[i][x][j]=1;
				}
			}
		}
		
		FOR(y,8) FOR(x,8) {
			FOR(j,cand[5].size()) {
				auto &c=cand[5][j];
				FOR(k,c.size()) {
					int cy=y+c[k].first;
					int cx=x+c[k].second;
					if(cy<0 || cy>=8 || cx<0 || cx>=8) break;
					if(S[cy][cx] != A[(K-1)/2+k]) break;
				}
				bs[j]=(k==c.size());
			}
			FOR(j,cand[(K-1)/2].size()) {
				auto &c=cand[(K-1)/2][j];
				FOR(k,c.size()) {
					int cy=y+c[k].first;
					int cx=x+c[k].second;
					if(cy<0 || cy>=8 || cx<0 || cx>=8) break;
					if(S[cy][cx] != A[(K-1)/2-k]) break;
				}
				if(k==c.size()) {
					bitset<16000> b=bs&c2[(K-1)/2][j];
					ret+=b.count();
				}
			}
			
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

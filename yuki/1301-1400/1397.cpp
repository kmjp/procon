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

int H,W,N;
map<vector<pair<int,int>>,ll> from[55],to[55];
const ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	int mask;
	FOR(mask,1<<(W+1)) {
		if(mask&&__builtin_popcount(mask)%2==0) {
			vector<pair<int,int>> V;
			FOR(i,7) if(mask&(1<<i)) {
				if(V.empty()||V.back().second!=-1) V.push_back({i,-1});
				else V.back().second=i;
			}
			int num=__builtin_popcount(mask)/2*3;
			from[num][V]++;
		}
	}
	ll ret=0;
	for(y=1;y<=H;y++) {
		FOR(i,55) to[i].clear();
		
		FOR(i,N) {
			FORR2(v,p,from[i]) if(i+v.size()==N) {
				vector<pair<int,int>> V=v;
				vector<int> R;
				sort(ALL(V));
				int pre=V[0].first;
				int ok=1;
				for(j=1;j<V.size();j++) {
					if(V[j].first<pre) ok=0;
					pre=V[j].second;
				}
				if(pre>V[0].second) ok=0;
				if(ok) (ret+=p*(H+1-y))%=mo;
				
			}
			FOR(mask,1<<(W+1)) if(mask&&__builtin_popcount(mask)%2==0) {
				FORR2(v,p,from[i]) {
					int over[7];
					int t[14];
					MINUS(over);
					MINUS(t);
					FORR(w,v) over[w.first]=w.second,over[w.second]=w.first;
					int pre=-1;
					int ng=0;
					int add=0;
					FOR(x,W+1) {
						if(over[x]>=0&&(mask&(1<<x))) {
							if(pre!=-1) ng=1;
							else t[x]=x+W+1,t[x+W+1]=x;
						}
						else if(over[x]>=0) {
							if(pre==-1) pre=x,add++;
							else t[pre]=x,t[x]=pre,pre=-1;
						}
						else if(mask&(1<<x)) {
							add++;
							if(pre==-1) pre=x+W+1,add++;
							else t[pre]=x+W+1,t[x+W+1]=pre,pre=-1;
						}
					}
					if(pre!=-1||ng) continue;
					if(i+add>N) continue;
					int vis[14]={};
					vector<pair<int,int>> NV;
					FOR(x,W+1) if(vis[x+W+1]==0&&t[x+W+1]>=0) {
						vis[x+W+1]=1;
						NV.push_back({x,0});
						j=t[x+W+1];
						while(j<W+1) {
							vis[j]=1;
							vis[over[j]]=1;
							j=t[over[j]];
						}
						vis[j]=1;
						j-=W+1;
						NV.back().second=j;
					}
					FOR(x,W+1) if(over[x]>=0&&vis[x]==0) ng=1;
					if(ng) continue;
					(to[i+add][NV]+=p)%=mo;
				}
			}
		}
		swap(from,to);
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

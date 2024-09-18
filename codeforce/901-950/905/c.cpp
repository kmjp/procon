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
ll A[505050];
int Q;
int L[505050],R[505050],X[505050];
vector<pair<int,int>> ev[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		FOR(i,N+1) {
			A[i]=0;
			ev[i].clear();
		}
		FOR(i,N) {
			scanf("%d",&x);
			A[i+1]+=x;
			A[i+2]-=x;
		}
		scanf("%d",&Q);
		FOR(i,Q) {
			scanf("%d%d%d",&L[i],&R[i],&X[i]);
			if(X[i]) {
				ev[L[i]-1].push_back({i+1,X[i]});
				ev[R[i]].push_back({i+1,-X[i]});
			}
		}
		set<pair<int,int>> cand={{0,Q+1}};
		FOR(y,N) if(ev[y].size()) {
			vector<pair<int,ll>> V={{0,0}};
			FORR2(t,x,ev[y]) {
				V.push_back({t,V.back().second+x});
			}
			V.push_back({Q+1,1LL<<60});
			ll mi=1LL<<60;
			FOR(i,V.size()-1) {
				int a=V[i].first;
				int b=V[i+1].first;
				auto it=cand.lower_bound({a,0});
				int in=0;
				if(it!=cand.end() && it->first<b) in=1;
				if(it!=cand.begin()&&prev(it)->second>a) in=1;
				if(in==1) {
					mi=min(mi,V[i].second);
				}
			}
			FOR(i,V.size()-1) {
				int a=V[i].first;
				int b=V[i+1].first;
				if(V[i].second==mi) continue;
				auto it=cand.lower_bound({a,0});
				if(it!=cand.begin()) {
					it--;
					if(it->first<a&&it->second>a) {
						auto p=*it;
						cand.erase(it);
						cand.insert({p.first,a});
						if(p.second>b) {
							cand.insert({b,p.second});
						}
					}
				}
				while(1) {
					auto it=cand.lower_bound({a,0});
					if(it==cand.end()) break;
					if(it->first>=b) break;
					if(it->second<=b) {
						cand.erase(it);
					}
					else {
						pair<int,int> p={b,it->second};
						cand.erase(it);
						cand.insert(p);
					}
				}
			}
		}
		x=cand.begin()->first;
		FOR(i,x) {
			A[L[i]]+=X[i];
			A[R[i]+1]-=X[i];
		}
		for(i=1;i<=N;i++) {
			A[i]+=A[i-1];
			cout<<A[i]<<" ";
		}
		cout<<"\n";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

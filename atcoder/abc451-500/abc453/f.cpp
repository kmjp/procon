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
int N,K;
vector<int> E[302020];
int C[302020];
int NC[302020],NS;

int cand2;
int ret[302020];
vector<int> VS[302020];

int dfs(int cur,int pre) {
	NC[cur]=E[cur].size()==1;
	vector<int> cand;
	FORR(e,E[cur]) if(e!=pre) {
		cand.push_back(dfs(e,cur));
		NC[cur]+=cand.back();
	}
	
	if(E[cur].size()!=1) {
		cand.push_back(NS-NC[cur]);
		sort(ALL(cand));
		if(cand.back()*2<=NS) cand2=cur;
	}
	return NC[cur];
	
}
void dfs2(int cur,int pre,int tar) {
	if(E[cur].size()==1) VS[tar].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,tar);
}
	
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		FOR(i,N) ret[i]=-1;
		
		int cand=-1;
		FOR(i,K) {
			cin>>C[i];
			if(C[i]>1) cand=i;
		}
		if(N==2) {
			if(cand!=-1) {
				cout<<cand+1<<" "<<cand+1<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else {
			int root;
			NS=0;
			FOR(i,N) {
				if(E[i].size()>1) root=i;
				if(E[i].size()==1) NS++;
			}
			cand2=-1;
			dfs(root,root);
			
			set<pair<int,int>> S;
			FORR(e,E[cand2]) {
				dfs2(e,cand2,e);
				S.insert({VS[e].size(),e});
			}
			FOR(i,K) if(C[i]>1) {
				if(S.empty()) break;
				if(S.size()==1) {
					x=S.begin()->second;
					ret[VS[x].back()]=i;
					VS[x].pop_back();
					ret[cand2]=i;
					S.clear();
					C[i]-=2;
					break;
				}
				else {
					auto p=*S.rbegin();
					S.erase(p);
					x=p.second;
					ret[VS[x].back()]=i;
					VS[x].pop_back();
					p=*S.rbegin();
					S.erase(p);
					y=p.second;
					ret[VS[y].back()]=i;
					VS[y].pop_back();
					if(VS[x].size()) S.insert({VS[x].size(),x});
					if(VS[y].size()) S.insert({VS[y].size(),y});
					C[i]-=2;
					
					while(S.size()&&C[i]) {
						auto p=*S.rbegin();
						S.erase(p);
						C[i]--;
						x=p.second;
						ret[VS[x].back()]=i;
						VS[x].pop_back();
						if(VS[x].size()) S.insert({VS[x].size(),x});
					}
				}
			}
			
			if(S.size()) {
				cout<<-1<<endl;
			}
			else {
				j=0;
				FOR(i,N) {
					if(ret[i]==-1) {
						while(C[j]==0) j++;
						ret[i]=j;
						C[j]--;
					}
					cout<<ret[i]+1<<" ";
				}
				cout<<endl;
				
			}
			
		}
		
		
		FOR(i,N) {
			E[i].clear();
			VS[i].clear();
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

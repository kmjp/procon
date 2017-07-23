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

int T;
int N;
set<int> E[101010];
int num[101010];
set<pair<int,int>> NS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		NS.clear();
		set<int> cand,ng;
		vector<int> ret;
		FOR(i,N) {
			NS.insert({E[i].size(),i});
			cand.insert(i);
		}
		
		FOR(i,N) {
			x = -1;
			int left=N-i;
			FORR(c,cand) {
				if(ng.count(c)) continue;
				if(E[c].size()+1==left && left!=1) continue;
				if(E[c].size()>1 || left==1) {
					x=c;
					break;
				}
				
				FORR(e,E[c]) {
					NS.erase({E[e].size(),e});
					E[e].erase(c);
					NS.insert({E[e].size(),e});
				}
				NS.erase({E[c].size(),c});
				
				auto mo=NS.rbegin();
				int ok=!(mo->first==left-2 && left>=3);
				
				NS.insert({E[c].size(),c});
				FORR(e,E[c]) {
					NS.erase({E[e].size(),e});
					E[e].insert(c);
					NS.insert({E[e].size(),e});
				}
				
				if(ok) {
					x=c;
					break;
				}
			}
			if(x==-1) {
				_P("-1\n");
				goto out;
			}
			cand.erase(x);
			ret.push_back(x);
			ng.clear();
			NS.erase({E[x].size(),x});
			FORR(e,E[x]) {
				NS.erase({E[e].size(),e});
				E[e].erase(x);
				ng.insert(e);
				NS.insert({E[e].size(),e});
			}
		}
		
		
		
		
		FOR(i,N) _P("%d%c",ret[i]+1,(i==N-1)?'\n':' ');
		out:;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

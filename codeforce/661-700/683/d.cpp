#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[202020];
vector<int> P[202020];
set<int> S;
int id[404040];
int pos[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		P[A[i]].push_back(i);
	}
	
	int ma=0,num=-1;
	FOR(i,N) ma=max(ma,(int)P[i].size());
	x=-1;
	FOR(i,N) if(P[i].size()==ma) {
		if(x==-1) {
			x=i;
			FORR(p,P[i]) S.insert(p);
		}
		else {
			cout<<N<<endl;
			return;
		}
	}
	MINUS(id);
	S.insert(N);
	int ret=0;
	FOR(i,N) {
		if(i==x||P[i].empty()) continue;
		if(P[i].size()<=400) {
			FORR(p,P[i]) S.insert(p);
			FORR(p,P[i]) {
				auto it=S.find(p);
				map<int,int> M;
				int cur=0;
				FOR(j,P[i].size()+1) {
					if(it==S.begin()) {
						M[cur]=0;
						break;
					}
					it--;
					M[cur]=*it+1;
					if(A[*it]==x) cur--;
					if(A[*it]==i) break;
				}
				it=S.find(p);
				cur=0;
				FOR(j,P[i].size()*2+1) {
					y=*it;
					if(M.count(cur)) ret=max(ret,y-M[cur]);
					if(y==N) break;
					if(A[y]==x) cur++;
					else cur--;
					it++;
				}
			}
			FORR(p,P[i]) S.erase(p);
		}
		else {
			int cur=202020;
			id[cur]=i;
			pos[cur]=0;
			FOR(j,N) {
				if(A[j]==i) cur++;
				if(A[j]==x) cur--;
				if(id[cur]==i) ret=max(ret,j+1-pos[cur]);
				else id[cur]=i, pos[cur]=j+1;
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

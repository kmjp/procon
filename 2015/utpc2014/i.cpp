#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

set<pair<int,int> > E[101000];
int N,Q;
int A[101000],B[101000],ID[101000];
int vis[101000];
int W[101000];
set<pair<int,int> > NE[101000];

void solve() {
	int i,j,k,l,r,x,y,cq; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>W[i];
		A[i]=x-1;
		B[i]=y-1;
		E[A[i]].insert(make_pair(i,B[i]));
		E[B[i]].insert(make_pair(i,A[i]));
		NE[0].insert(make_pair(W[i],i));
	}
	
	cin>>Q;
	FOR(cq,Q) {
		cin>>i>>x;
		x--;
		if(i==1) {
			cin>>y;
			if(ID[x]!=-1) {
				NE[ID[x]].erase(make_pair(W[x],x));
				W[x]+=y;
				NE[ID[x]].insert(make_pair(W[x],x));
			}
		}
		else if(i==2) {
			int id=ID[x];
			if(id==-1) {
				cout<<-1<<endl;
				continue;
			}
			x=NE[id].begin()->second;
			cout<<x+1<<endl;
			
			ID[x]=-1;
			NE[id].erase(NE[id].begin());
			E[A[x]].erase(make_pair(x,B[x]));
			E[B[x]].erase(make_pair(x,A[x]));
			
			queue<pair<int,set<pair<int,int> >::iterator> > q[2];
			vector<int> v[2];
			q[0].push(make_pair(A[x],E[A[x]].begin()));
			q[1].push(make_pair(B[x],E[B[x]].begin()));
			vis[A[x]]=vis[B[x]]=cq+1;
			v[0].push_back(A[x]);
			v[1].push_back(B[x]);
			
			while(q[0].size() && q[1].size()) {
				FOR(i,2) {
					while(q[i].size()) {
						auto& qe = q[i].front();
						while(qe.second != E[qe.first].end()) {
							y = (qe.second++)->second;
							if(vis[y] != cq+1) {
								vis[y] = cq+1;
								q[i].push(make_pair(y,E[y].begin()));
								v[i].push_back(y);
								goto out;
							}
						}
						q[i].pop();
					}
					out:
					;
				}
			}
			int smaller = q[0].size()>q[1].size();
			FORR(r,v[smaller]) {
				FORR(e2,E[r]) if(e2.second<r) {
					ID[e2.first]=cq+1;
					NE[id].erase(make_pair(W[e2.first],e2.first));
					NE[cq+1].insert(make_pair(W[e2.first],e2.first));
				}
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

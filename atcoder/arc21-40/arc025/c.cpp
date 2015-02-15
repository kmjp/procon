#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,R,T;
ll D[4000];
vector<pair<ll,int> > E[3000];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>R>>T;
	FOR(i,M) {
		cin>>x>>y>>j;
		E[x-1].push_back(make_pair(1LL*j*R*T,y-1));
		E[y-1].push_back(make_pair(1LL*j*R*T,x-1));
	}
	
	ll ret=0;
	FOR(i,N) {
		FOR(x,N) D[x]=1LL<<60;
		D[i]=0;
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q;
		Q.push(make_pair(0,i));
		while(!Q.empty()) {
			pair<int,int> k=Q.top();
			Q.pop();
			int cur=k.second;
			if(k.first != D[cur]) continue;
			
			FOR(j,E[cur].size()) {
				int tar=E[cur][j].second;
				if(D[tar] > D[cur]+E[cur][j].first) {
					D[tar] = D[cur]+E[cur][j].first;
					Q.push(make_pair(D[tar],tar));
				}
			}
		}
		vector<ll> V;
		FOR(x,N) if(x!=i) V.push_back(D[x]/R);
		sort(V.begin(),V.end());
		FOR(j,V.size()) {
			ll t=V[j]*R/T;
			vector<ll>::iterator it=upper_bound(V.begin(),V.end(),t);
			int id=it-V.begin();
			if(id>j) ret+=V.size()-id;
			else ret+=V.size()-id-1;
		}
	}
	cout << ret << endl;
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}



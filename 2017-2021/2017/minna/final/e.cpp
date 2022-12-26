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

int N,M,Q;
vector<int> E[101010];
set<pair<int,int>> S;

int id[101010];
vector<vector<int>> Ds;
vector<int> D;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
		S.insert({x,y});
	}
	FOR(i,N) sort(ALL(E[i]));
	
	x = 0;
	FOR(i,N) {
		if(E[i].size()<N/2-2) {
			id[i]=-1;
		}
		else {
			id[i]=x++;
			D = vector<int>(N,-1);
			vector<int> left;
			FOR(j,N) if(i!=j) left.push_back(j);
			D[i]=0;
			queue<int> Q;
			Q.push(i);
			while(Q.size()) {
				y = Q.front();
				Q.pop();
				
				vector<int> left2;
				int u=0,v=0;
				while(u<left.size()) {
					if(v<E[y].size() && left[u]==E[y][v]) {
						left2.push_back(E[y][v]);
						u++, v++;
					}
					else if(v==E[y].size() || left[u]<E[y][v]) {
						D[left[u]]=D[y]+1;
						Q.push(left[u]);
						u++;
					}
					else {
						v++;
					}
				}
				swap(left,left2);
			}
			
			Ds.push_back(D);
		}
	}
	
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(S.count({x,y})==0) {
			cout<<1<<endl;
		}
		else if(E[x].size()+E[y].size()<N-2) {
			cout<<2<<endl;
		}
		else {
			if(E[x].size()<E[y].size()) swap(x,y);
			cout<<Ds	[id[x]][y]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

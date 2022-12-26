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

#include "stray.h"

vector<pair<int,int>> E[202020];
vector<int> X;
vector<int> S={0,1,0,0,1,1};
int D[202020];

void dfs(int cur,int pre,int id) {
	if(E[cur].size()>2) {
		if(S[id]==0) {
			FORR(e,E[cur]) if(e.first!=pre) {
				X[e.second]=1;
				dfs(e.first,cur,1);
			}
		}
		else {
			FORR(e,E[cur]) if(e.first!=pre) {
				X[e.second]=0;
				dfs(e.first,cur,0);
			}
		}
	}
	else {
		id=(id+1)%6;
		FORR(e,E[cur]) if(e.first!=pre) {
			X[e.second]=S[id];
			dfs(e.first,cur,id);
		}
	}
}

std::vector<int> Mark(int N, int M, int A, int B,
                      std::vector<int> U, std::vector<int> V) {
	X.resize(M);
	int i;
	FOR(i,M) {
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
	}
	
	if(A>=3) {
		FOR(i,N) D[i]=202020;
		D[0]=0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(D[e.first]>D[cur]+1) {
				D[e.first]=D[cur]+1;
				Q.push(e.first);
			}
		}
		FOR(i,M) {
			X[i]=min(D[U[i]],D[V[i]])%3;
		}
	}
	else {
		FORR(e,E[0]) {
			X[e.second]=0;
			dfs(e.first,0,0);
		}
	}
	return X;
}

int A,B;
int last=-1;
int fix=0;
vector<int> V;

void Init(int A, int B) {
  ::A = A;
  ::B = B;
  last=-1;
}

int Move(std::vector<int> y) {
	if(A>=3) {
		if(last!=-1) y[last]++;
		
		if(y[0]>0 && y[1]>0) last=0;
		else if(y[1]>0 && y[2]>0) last=1;
		else if(y[2]>0 && y[0]>0) last=2;
		else if(y[0]) last=0;
		else if(y[1]) last=1;
		else last=2;
		
	}
	else {
		int num=y[0]+y[1]+(last!=-1);
		//cout<<last<<" "<<y[0]<<" "<<y[1]<<" "<<num<<" "<<fix<<endl;
		if(num>=3) {
			
			fix=1;
			if(last>=0) {
				if(y[0]==0) return -1;
				if(y[1]==0) return -1;
				y[last]++;
			}
			assert(min(y[0],y[1])==1);
			if(y[0]<y[1]) last=0;
			else last=1;
		}
		else if(num==1) {
			fix=1;
			if(last>=0) return -1;
			if(y[0]) last=0;
			else last=1;
		}
		else if(fix) {
			if(y[0]) last=0;
			else last=1;
		}
		else if(last==-1) {
			int i;
			FOR(i,y[0]) V.push_back(0);
			FOR(i,y[1]) V.push_back(1);
			last=V.back();
		}
		else {
			if(y[0]) V.push_back(0);
			if(y[1]) V.push_back(1);
			y[last]++;
			
			if(V.size()==5) {
				int num=3;
				FORR(v,V) num-=v;
				V.push_back(num);
				int rev=0;
				int i;
				FOR(i,6) {
					rotate(V.begin(),V.begin()+1,V.end());
					rev+=V==S;
				}
				/*cout<<"!";
				FORR(v,V) cout<<v<<endl;
				cout<<rev<<endl;*/
				fix=1;
				if(rev) {
					return -1;
				}
			}
			y[last]--;
			if(y[0]) last=0;
			else last=1;
		}
		//cout<<"!"<<num<<" "<<last<<" "<<y[0]<<" "<<y[1]<<endl;
		assert(y[last]);
	}
	return last;
}


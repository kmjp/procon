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

int N,K,M,S;
int R[101010];
set<int> L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M>>S;
	S--;
	FOR(i,M) cin>>x, R[x-1]=-1;
	FOR(i,N) if(R[i]==0 && i!=S) R[i]=1010100, L.insert(i);
	
	queue<int> Q;
	Q.push(S);
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		x=(k-(K-1)>=0)?(k-(K-1)):(K-1-k);
		y=(k+(K-1)<N)?(k+(K-1)):(N-(K+1)+(N-k));
		for(auto it=L.lower_bound(x);it!=L.end() && *it<=y;) {
			if(K%2==abs(k-*it)%2) {
				it++;
			}
			else {
				R[*it]=R[k]+1;
				Q.push(*it);
				it=L.erase(it);
			}
		}
	}
	
	FOR(i,N) {
		if(R[i]>1010000) R[i]=-1;
		_P("%d%c",R[i],(i==N-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

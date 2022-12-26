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

int N,K;
int C[202020];
ll V[202020];
vector<ll> cand[202020];
int id[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>C[i]>>V[i];
		C[i]--;
		cand[C[i]].push_back(V[i]*2);
	}
	
	multiset<pair<ll,int>> P,Q,R,S,T;
	vector<vector<ll>> ev;
	FOR(i,K) {;
		sort(ALL(cand[i]));
		cand[i][cand[i].size()-2]=cand[i][cand[i].size()-1]=(cand[i][cand[i].size()-1]+cand[i][cand[i].size()-2])/2;
		reverse(ALL(cand[i]));
		S.insert({cand[i][0]+cand[i][1],i});
		if(cand[i].size()>=3) T.insert({cand[i][0]+cand[i][1]+cand[i][2],i});
		FOR(j,cand[i].size()) ev.push_back({-cand[i][j],i,j});
	}
	
	sort(ALL(ev));
	ll cur=0;
	FOR(i,N) {
		auto e=ev[i];
		x=e[1];
		
		if(e[2]==0) {
			ll ret=-2;
			if(Q.size()) ret=max(ret,cur+Q.rbegin()->first);
			if(P.size()&&S.size()) ret=max(ret,cur-P.begin()->first+S.rbegin()->first);
			if(R.size()&&T.size()) ret=max(ret,cur-R.begin()->first+T.rbegin()->first);
			cout<<ret/2<<endl;
		}
		else {
			
			if(e[2]==1) {
				cur-=2*e[0];
				S.erase({cand[x][0]+cand[x][1],x});
				if(cand[x].size()>=3) T.erase({cand[x][0]+cand[x][1]+cand[x][2],x});
				R.insert({cand[x][0]+cand[x][1],x});
				id[x]=2;
				if(id[x]<cand[x].size()) Q.insert({cand[x][id[x]],x});
			}
			else {
				cur-=e[0];
				if(id[x]==2) R.erase({cand[x][0]+cand[x][1],x});
				else P.erase({cand[x][id[x]-1],x});
				Q.erase({cand[x][id[x]],x});
				P.insert({cand[x][id[x]],x});
				id[x]++;
				if(id[x]<cand[x].size()) Q.insert({cand[x][id[x]],x});
			}
			cout<<cur/2<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

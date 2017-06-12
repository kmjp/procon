#include <message.h>
#include <cassert>
#include <cstdio>
#include "broken_memory.h"
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

int TN,MY;
int N;
ll V[1010][1010];
vector<ll> D;

template<class V> struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<int> pmo[2];
	V s; int l; vector<int> hash_[2];
	void init(V s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<int>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i]%mo0)%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i]%mo1)%mo1);
	}
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(1LL*pmo[0].back()*mul0%mo0), pmo[1].push_back(1LL*pmo[1].back()*mul1%mo1);
		ll a=(hash_[0][r+1]+(mo0-1LL*hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0;
		ll b=(hash_[1][r+1]+(mo1-1LL*hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1;
		return (a<<32)|b;
	}
};
template<typename V> vector<int> RollingHash<V>::pmo[2];
template<typename V> ll RollingHash<V>::mul0;
template<typename V> ll RollingHash<V>::mul1;

RollingHash<vector<ll>> rh;

void slow() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N) PutLL(0,GetValue(i));
	Send(0);
	if(MY!=0) return;
	
	FOR(i,TN) {
		Receive(i);
		FOR(x,N) V[i][x]=GetLL(i);
	}
	
	int ret[100]={};
	FOR(x,N) {
		FOR(i,TN) {
			if(V[(i+TN-1)%TN][x]==V[(i+1)%TN][x] && V[i][x]!=V[(i+1)%TN][x]) ret[i]=x;
		}
	}
	FOR(i,TN) _P("%d%c",ret[i],(i==TN-1)?'\n':' ');
	
}


int ask(int L,int R,int pa) {
	while(L+1<R) {
		int M=(L+R)/2;
		
		ll myh=rh.hash(L,M-1);
		PutInt(pa,L);
		PutInt(pa,M-1);
		Send(pa);
		Receive(pa);
		ll tarh=GetLL(pa);
		
		if(myh==tarh) L=M;
		else R=M;
	}
	PutInt(pa,-1);
	Send(pa);
	return L;
}
void ans(int pa) {
	while(1) {
		Receive(pa);
		int L=GetInt(pa);
		if(L<0) break;
		int R=GetInt(pa);
		
		PutLL(pa,rh.hash(L,R));
		Send(pa);
	}
}

void fast() {
	int i,j,k,l,r,x,y; string s;
	
	D.resize(N);
	FOR(i,N) D[i]=GetValue(i);
	rh.init(D);
	
	if(MY==0) {
		int L=2,R=N-2,M;
		map<ll,int> P;
		
		ll ha[101];
		while(L+1<R) {
			M=(L+R)/2;
			P.clear();
			ha[0]=rh.hash(0,M-1);
			P[ha[0]]++;
			
			for(i=1;i<TN;i++) {
				PutInt(i,M);
				Send(i);
			}
			for(i=1;i<TN;i++) {
				Receive(i);
				ha[i]=GetLL(i);
				P[ha[i]]++;
			}
			
			if(P.size()-1==TN/2) break;
			if(P.size()-1<TN/2) L=M;
			else R=M;
		}
		for(i=1;i<TN;i++) {
			PutInt(i,-1);
			Send(i);
		}
		vector<int> C[2];
		FOR(i,TN) {
			if(P[ha[i]]==1) C[0].push_back(i);
			else C[1].push_back(i);
		}
		assert(C[0].size()==TN/2);
		assert(C[1].size()==TN/2);
		FOR(i,TN/2) {
			PutInt(C[0][i],0);
			PutInt(C[0][i],M);
			PutInt(C[0][i],C[1][i]);
			Send(C[0][i]);
			PutInt(C[1][i],M);
			PutInt(C[1][i],N);
			PutInt(C[1][i],C[0][i]);
			Send(C[1][i]);
		}
	}
	else {
		while(1) {
			Receive(0);
			int M=GetInt(0);
			if(M==-1) break;
			PutLL(0,rh.hash(0,M-1));
			Send(0);
		}
	}
	
	Receive(0);
	int L=GetInt(0);
	int R=GetInt(0);
	int pa=GetInt(0);
	int ret;
	if(MY<pa) {
		ret=ask(L,R,pa);
		ans(pa);
	}
	else {
		ans(pa);
		ret=ask(L,R,pa);
	}
	
	PutInt(0,ret);
	Send(0);
	
	if(MY==0) {
		FOR(i,TN) {
			Receive(i);
			_P("%d%c",GetInt(i),(i==TN-1)?'\n':' ');
		}
	}
	
}

void solve(){
	N=GetLength();
	
	if(N<=100) slow();
	else fast();
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}



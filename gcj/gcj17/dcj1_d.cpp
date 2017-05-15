#include <message.h>
#include <cassert>
#include <cstdio>
#include "todd_and_steven.h"
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
ll NO,NE;
ll mo=1000000007;

void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY!=0) return;
	
	x=y=0;
	ll O=(x==NO)?1LL<<60:GetToddValue(x);
	ll E=(y==NE)?1LL<<60:GetStevenValue(y);
	ll ret=0;
	ll id=0;
	while(x<NO || y<NE) {
		if(O<E) {
			(ret += O^id)%=mo;
			x++;
			O=(x==NO)?1LL<<60:GetToddValue(x);
		}
		else {
			(ret += E^id)%=mo;
			y++;
			E=(y==NE)?1LL<<60:GetStevenValue(y);
		}
		id++;
	}
	
	cout<<ret<<endl;
}

int numO(ll v) {
	int num=0;
	for(int i=30;i>=0;i--) if(num+(1<<i) <= NO && GetToddValue(num+(1<<i)-1)<=v) num+=1<<i;
	return num;
}

int numE(ll v) {
	int num=0;
	for(int i=30;i>=0;i--) if(num+(1<<i) <= NE && GetStevenValue(num+(1<<i)-1)<=v) num+=1<<i;
	return num;
}

void fast() {
	ll L=(NO+NE)*MY/TN;
	ll R=(NO+NE)*(MY+1)/TN;
	
	ll v=0;
	for(int i=35;i>=0;i--) if(numO(v+(1LL<<i))+numE(v+(1LL<<i))<=L) v+=1LL<<i;
	
	int x=numO(v), y=numE(v);
	ll ret=0;
	ll O=(x==NO)?1LL<<40:GetToddValue(x);
	ll E=(y==NE)?1LL<<40:GetStevenValue(y);
	for(ll i=L;i<R;i++) {
		if(O<E) {
			(ret += O^i)%=mo;
			x++;
			O=(x==NO)?1LL<<60:GetToddValue(x);
		}
		else {
			(ret += E^i)%=mo;
			y++;
			E=(y==NE)?1LL<<60:GetStevenValue(y);
		}
	}
	
	PutInt(0,ret);
	Send(0);
	if(MY!=0) return;
	
	ret=0;
	int i;
	FOR(i,TN) {
		Receive(i);
		ret += GetInt(i);
	}
	
	cout<<ret%mo<<endl;
	
}


void solve(){
	
	
	NO=GetToddLength();
	NE=GetStevenLength();
	
	if(NO+NE<1000) slow();
	else fast();
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}



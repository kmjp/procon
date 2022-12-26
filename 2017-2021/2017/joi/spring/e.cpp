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
#include "Broken_device_lib.h"

//#include "Annalib.h"
//#include "Brunolib.h"

void goset(int i,string s) {
	//cout<<i<<endl;
	Set(i,s[0]-'0');
	Set(i+1,s[1]-'0');
	Set(i+2,s[2]-'0');
	
}

void Anna( int N, long long X, int K, int P[] ){
	int NG[150]={};
	int i;
	FOR(i,K) NG[P[i]]=1;
	for(i=0;i<150;i+=3) {
		int ng=NG[i]+NG[i+1]+NG[i+2];
		if(ng==0) {
			if(X%4==0) goset(i,"100");
			if(X%4==1) goset(i,"011");
			if(X%4==2) goset(i,"101");
			if(X%4==3) goset(i,"111");
			X>>=2;
		}
		else if(ng==1) {
			if(NG[i]) {
				if(X%2==0) goset(i,"010");
				if(X%2==1) goset(i,"001");
				X>>=1;
			}
			if(NG[i+1]) {
				if(X%2==1) {
					goset(i,"001");
					X>>=1;
				}
				else {
					X>>=1;
					if(X%2==0) goset(i,"100");
					if(X%2==1) goset(i,"101");
					X>>=1;
				}
			}
			if(NG[i+2]) {
				if(X%2==0) goset(i,"010");
				if(X%2==1) goset(i,"110");
				X>>=1;
			}
		}
		else {
			goset(i,"000");
		}
	}
}

long long Bruno( int N, int A[] ){
	int cur=0;
	ll V=0;
	int i;
	for(i=0;i<N;i+=3) {
		if(cur>=60) break;
		if(A[i]==0&&A[i+1]==0&&A[i+2]==0) {
			continue;
		}
		if(A[i]==0&&A[i+1]==0&&A[i+2]==1) {
			V|=1LL<<cur;
			cur++;
		}
		if(A[i]==0&&A[i+1]==1&&A[i+2]==0) {
			cur++;
		}
		if(A[i]==0&&A[i+1]==1&&A[i+2]==1) {
			V|=1LL<<cur;
			cur+=2;
		}
		if(A[i]==1&&A[i+1]==0&&A[i+2]==0) {
			cur+=2;
		}
		if(A[i]==1&&A[i+1]==0&&A[i+2]==1) {
			V|=2LL<<cur;
			cur+=2;
		}
		if(A[i]==1&&A[i+1]==1&&A[i+2]==0) {
			V|=1LL<<cur;
			cur++;
		}
		if(A[i]==1&&A[i+1]==1&&A[i+2]==1) {
			V|=3LL<<cur;
			cur+=2;
		}
		
	}
	
	return V;
}

#include "grader.h"

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

int AX;
int BX;
int AT;
int BT;
int turn[2];
vector<pair<int,int> > H[2];
int PI[2],PJ[2];

bool hist(int id,int I,int J) {
	PI[id]=I;
	PJ[id]=J;
	bool other=(H[id].size() && H[id].back()!=make_pair(I,J));
	H[id].push_back(make_pair(I,J));
	return other;
}

int add(int id,int di,int dj) {
	H[id].push_back(make_pair(PI[id]+di,PJ[id]+dj));
	//cout<<"move to "<<PI[id]+di<<","<<PJ[id]+dj<<endl;
	if(di==-1) return -1;
	if(di==1) return -2;
	if(dj==-1) return -3;
	return -4;
}



void InitA(int T, int X) {
	AX=X;
	AT=0;
	turn[0]=0;
	H[0].clear();
	srand(time(NULL));
}

int GameA(int I, int J) {
	int id=0;
	int other=hist(id,I,J);
	//cout<<"A "<<turn[id]<<" "<<I<<J<<" "<<AT<<endl;
	if(turn[id]<18) {
		if(other) {
			turn[id]=100;
		}
		else {
			if(I>1) return add(id,-1,0);
			if(J==1) return add(id,0,1);
			if(J==4) return add(id,0,-1);
			if(rand()<RAND_MAX/2) {
				return add(id,0,1);
			}
			else {
				return add(id,0,-1);
			}
		}
	}
	if(I==1) return add(id,1,0);
	if(I==2) {
		if(AX&(1<<AT)) {
			if(J>2) {
				AT++;
				return add(id,1,0);
			}
			else {
				return add(id,0,1);
			}
		}
		else {
			if(J<=2) {
				AT++;
				return add(id,1,0);
			}
			else {
				return add(id,0,-1);
			}
		}
	}
	if(I==3) {
		if(AX&(1<<(AT-1))) {
			if(J==3) return add(id,0,1);
			if(J==4) return add(id,0,-1);
			assert(0);
		}
		else {
			if(J==1) return add(id,0,1);
			if(J==2) return add(id,0,-1);
			assert(0);
		}
	}
	assert(0);
	return -1;
}

void InitB(int T) {
	BT=BX=0;
	turn[1]=0;
	H[1].clear();
	srand(time(NULL));
}

int GameB(int I, int J) {
	int id=1;
	int other=hist(id,I,J);
	//cout<<"B "<<turn[id]<<" "<<I<<J<<" "<<BT<<" "<<BX<<endl;
	if(turn[id]<18||I==1) {
		if(other) {
			turn[id]=100;
		}
		else {
			if(I>1) return add(id,-1,0);
			if(J==1) return add(id,0,1);
			if(J==4) return add(id,0,-1);
			if(rand()<RAND_MAX/2) {
				return add(id,0,1);
			}
			else {
				return add(id,0,-1);
			}
		}
	}
	if(I<=2) {
		if(J==1) return add(id,0,1);
		if(J==4) return add(id,0,-1);
		if(rand()<RAND_MAX/2) {
			return add(id,0,1);
		}
		else {
			return add(id,0,-1);
		}
	}
	assert(I==3);
	if(J>=3) {
		BX|=1<<BT;
	}
	
	BT++;
	if(BT>=30) return BX;
	return add(id,-1,0);
}

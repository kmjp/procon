#include "grader.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

vector<pair<int,int> > E;
vector<int> left;
int RL[101010],RR[101010];
int CL[101010],CR[101010];

void schedule(int W, int N, int X[], int D[]) {
	int i;
	
	FOR(i,N) {
		E.push_back(make_pair(max(0,X[i]-D[i]+1),0));
		E.push_back(make_pair(min(W-1,X[i]+D[i]-1),1));
		CR[i+1]=RR[i+1]=-10;
	}
	sort(ALL(E));
	int num=0;
	ITR(it,E) {
		if(it->second==0) {
			num++;
			if(it->first>CR[num]+1) CL[num]=it->first;
		}
		else {
			if(RR[num]-RL[num]<it->first-CL[num]) {
				RL[num]=CL[num];
				RR[num]=it->first;
			}
			CR[num]=it->first;
			num--;
		}
	}
	
	
	FOR(i,N) {
		if(RR[i+1]<0) RR[i+1]=0;
		answer(i+1, RL[i+1],RR[i+1]);
	}
}


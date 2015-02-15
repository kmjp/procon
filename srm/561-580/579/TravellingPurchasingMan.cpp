#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll cost[100][100];
ll minc[17][1<<17];

class TravellingPurchasingMan {
	public:
	
	vector<vector<int> > S;
	vector<vector<int> > R;
	vector<int> split_int(const string &str, char delim){
		vector<int> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			string s = string(str, current, found - current);
			res.push_back(atoi(s.c_str()));
			current = found + 1;
		}
		string s = string(str, current, str.size() - current);
		res.push_back(atoi(s.c_str()));
		return res;
	}
	
	inline int bitcount(unsigned int n) { return __builtin_popcount(n);}
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
		int NS=interestingStores.size();
		int i,j,k;
		
		S.clear();
		FOR(i,NS) S.push_back(split_int(interestingStores[i],' '));
		FOR(i,N) {
			FOR(j,N) cost[i][j]=1LL<<50;
			cost[i][i]=0;
		}
		
		FOR(i,roads.size()) {
			vector<int> ss=split_int(roads[i],' ');
			cost[ss[0]][ss[1]]=cost[ss[1]][ss[0]]=ss[2];
		}
		FOR(i,N) FOR(j,N) FOR(k,N) cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
		FOR(i,17) FOR(j,1<<17) minc[i][j]=(1LL<<50);
		FOR(i,NS) minc[i][0]=cost[i][N-1];
		
		int mask,cur,tar;
		int res=0;
		for(int mask=0;mask<(1<<NS);mask++) {
			FOR(cur,NS) {
				if(cost[cur][N-1]==(1LL<<50)) continue;
				if(minc[cur][mask]==(1LL<<50)) continue;
				res = max(res, __builtin_popcount(mask));
				
				FOR(tar,NS) {
					if(mask & (1<<tar)) continue;
					ll mi=max((ll)S[tar][0],minc[cur][mask] + cost[cur][tar]);
					if(mi<=S[tar][1]) minc[tar][mask | (1<<tar)] = min(minc[tar][mask | (1<<tar)] , mi+S[tar][2]);
				}
			}
		}
		
		return res;
	}
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

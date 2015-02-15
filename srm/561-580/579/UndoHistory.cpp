
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


class UndoHistory {
	public:
	set<string> Vs;
	
	int minPresses(vector <string> lines) {
		int L=lines.size();
		
		Vs.clear();
		int i,j;
		int res=lines[0].size()+1;
		Vs.insert("");
		FOR(j,lines[0].size()+1) Vs.insert(lines[0].substr(0,j));
		
		for(i=1;i<L;i++) {
			int mi=9999;
			
			if(lines[i-1].size()<=lines[i].size() && lines[i-1]==lines[i].substr(0,lines[i-1].size()))
				mi=lines[i].size()-lines[i-1].size();
				
			FOR(j,lines[i].size()+1) {
				if(Vs.find(lines[i].substr(0,j))!=Vs.end()) mi=min(mi,2+(int)lines[i].size()-j);
			}
			res += mi+1;
			FOR(j,lines[i].size()+1) Vs.insert(lines[i].substr(0,j));
		}
		return res;
		
	}
};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

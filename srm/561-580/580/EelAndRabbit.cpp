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

inline ll bitcount(ll n) { return __builtin_popcountll(n);}

class EelAndRabbit {
	map<int,int> S;
	int N;
	ll mask[101];
	public:
	int getmax(vector <int> l, vector <int> t) {
		int i,j;
		S.clear();
		N=l.size();
		FOR(i,N) {
			l[i]+=t[i];
			S[l[i]]=1;
			S[t[i]]=1;
		}
		
		i=0;
		for(map<int,int>::iterator mit=S.begin();mit!=S.end();mit++) mit->second=i++;
		
		FOR(i,N) {
			l[i]=S[l[i]];
			t[i]=S[t[i]];
		}
		
		ZERO(mask);
		FOR(i,101) {
			FOR(j,N) {
				if(i>=t[j] && i<=l[j]) mask[i] |= 1LL<<j;
			}
		}
		
		int ma=0;
		FOR(i,101) {
			FOR(j,101) {
				ma=max(ma,(int)bitcount(mask[i]|mask[j]));
			}
		}
		return ma;
		
		
		
		
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

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

#include "grader.h"
int H[202][202];
int XX;

int get(int r,int c) {
	if(H[r][c]==0) {
		H[r][c]=Measure(r,c);
	}
	if(H[r][c]==XX) Pinpoint(r,c);
	return H[r][c];
}


void Rescue(int R, int C, int RS, int CS, int X) {
	ZERO(H);
	XX=X;
	
	int x,y;
	x=1;
	for(y=RS;y>=1;y--) {
		get(y,x);
		while(x<CS&&get(y,x+1)<=X) x++;
	}
	x=C;
	for(y=RS;y>=1;y--) {
		get(y,x);
		while(x>CS&&get(y,x-1)<=X) x--;
	}
	x=1;
	for(y=RS;y<=R;y++) {
		get(y,x);
		while(x<CS&&get(y,x+1)<=X) x++;
	}
	x=C;
	for(y=RS;y<=R;y++) {
		get(y,x);
		while(x>CS&&get(y,x-1)<=X) x--;
	}
	
}


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

vector<int> V= {
         1,
         2,
         4,
         6,
        12,
        24,
        36,
        48,
        60,
       120,
       180,
       240,
       360,
       720,
       840,
      1260,
      1680,
      2520,
      5040,
      7560,
     10080,
     15120,
     20160,
     25200,
     27720,
     45360,
     50400,
     55440,
     83160,
    110880,
    166320,
    221760,
    277200,
    332640,
    498960,
    554400,
    665280,
    720720,
   1081080,
   1441440,
   2162160,
   2882880,
   3603600,
   4324320,
   6486480,
   7207200,
   8648640,
  10810800,
  14414400,
  17297280,
  21621600,
  32432400,
  36756720,
  43243200,
  61261200,
  73513440,
 110270160,
 122522400,
 147026880,
 183783600,
 245044800,
 294053760,
 367567200,
 551350800,
 698377680,
 735134400,
1102701600,
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x;
	cout<<V[lower_bound(ALL(V),x+1)-V.begin()-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

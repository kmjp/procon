#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,K;
string S;
int num[26];

int okok(int cur,int kk) {
	int i;
	int nn[26];
	memmove(nn,num,sizeof(nn));
	
	for(i=cur+1;i<N;i++) {
		if(nn[S[i]-'a']) nn[S[i]-'a']--;
		else kk--;
	}
	return kk>=0;
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K>>S;
	int vis[101];
	ZERO(vis);
	FOR(i,N) num[S[i]-'a']++;
	string T;
	
	FOR(i,N) {
		FOR(j,26) {
			if(num[j]) {
				num[j]--;
				if(j+'a'==S[i]) {
					if(okok(i,K)) break;
				}
				else {
					if(okok(i,K-1)) {
						K--;
						break;
					}
				}
				num[j]++;
			}
		}
		T+='a'+j;
	}
	cout << T << endl;
	
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}



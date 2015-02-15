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

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
pair<int,int> L[100001];
string C;
string A;
int md=11;

vector<string> split(const string &str, char delim){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

pair<int,int> sp1(string ss) {
	ss=ss.substr(1,ss.size()-2); // del par
	vector<string> Cs=split(ss,'v');
	pair<int,int> p;
	
	if(Cs[0][0]=='~') p.first=-1*atoi(Cs[0].c_str()+1);
	else p.first=atoi(Cs[0].c_str());
	if(Cs[1][0]=='~') p.second=-1*atoi(Cs[1].c_str()+1);
	else p.second=atoi(Cs[1].c_str());
	
	return p;
}

void go(int depth) {
	int i;
	if(depth>=md) return;
	
	FOR(i,M) {
		int lv=A[abs(L[i].first)-1],lpv=lv;
		int rv=A[abs(L[i].second)-1],rpv=rv;
		if(L[i].first<0) lv^=1;
		if(L[i].second<0) rv^=1;
		
		if(lv==0 && rv==0) {
			A[abs(L[i].first)-1]^=1;
			go(depth+1);
			A[abs(L[i].first)-1]=lpv;
			A[abs(L[i].second)-1]^=1;
			go(depth+1);
			A[abs(L[i].second)-1]=rpv;
			return;
		}
	}
	md=min(md,depth);
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M;
	cin>>C;
	cin>>A;
	
	FOR(i,N) A[i]=(A[i]=='T');
	
	vector<string> Cs=split(C,'^');
	FOR(i,M) L[i]=sp1(Cs[i]);
	go(0);
	
	if(md>=11) _P("TOO LARGE\n");
	else _P("%d\n",md);
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}



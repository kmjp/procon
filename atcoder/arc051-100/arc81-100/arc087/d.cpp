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

string S;
int X,Y;
bitset<40000> B;
int hoge(vector<int> V,int X) {
	B.reset();
	B[X+20000]=1;
	FORR(v,V) {
		B=(B>>v)|(B<<v);
	}
	return B[20000];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X>>Y;
	reverse(ALL(S));
	while(S.size()&&S.back()=='F') {
		X--;
		S.pop_back();
	}
	
	
	vector<int> V[2];
	x=0;
	while(S.size()) {
		if(S.back()=='T') {
			x^=1;
			V[x].push_back(0);
		}
		else {
			V[x].back()++;
		}
		S.pop_back();
	}
	
	if(hoge(V[0],X) && hoge(V[1],Y)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

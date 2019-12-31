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

string S,T;
struct node {
	int V,L,R;
};
node nodes[202020];
int N=1;
int RN[2];

int create(string& S,int& pos) {
	if(S[pos]==')') return -1;
	int cur=N++;
	pos++;
	nodes[cur].L=create(S,pos);
	pos++;
	assert(S[pos]=='[');
	pos++;
	nodes[cur].V=0;
	while(S[pos]!=']') nodes[cur].V=nodes[cur].V*10+S[pos++]-'0';
	pos++;
	pos++;
	nodes[cur].R=create(S,pos);
	pos++;
	return cur;
}

void output(int L,int R) {
	if(L==-1 || R==-1) return;
	cout<<"(";
	output(nodes[L].L,nodes[R].L);
	cout<<")["<<(nodes[L].V+nodes[R].V)<<"](";
	output(nodes[L].R,nodes[R].R);
	cout<<")";
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	int pos=0;
	RN[0]=create(S,pos);
	pos=0;
	RN[1]=create(T,pos);
	
	output(RN[0],RN[1]);
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

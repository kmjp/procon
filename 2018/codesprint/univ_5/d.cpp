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

struct Node {
	ll v;
	Node *L,*R;
	Node() { v=0, L=R=NULL;}
};

Node head;

int N,K;
int A[101010];
int B[101010];

void add(Node* now,ll k,int level,ll v) {
	now->v+=v;
	if(level==-1) return;
	if(k&(1LL<<level)) {
		if(now->R==NULL) now->R=new Node();
		add(now->R,k,level-1,v);
	}
	else {
		if(now->L==NULL) now->L=new Node();
		add(now->L,k,level-1,v);
	}
}

ll ask(Node* now,int k,int level) {
	ll ret=0;
	if(now==NULL || level<0) return 0;
	if(K&(1<<level)) {
		if(k&(1<<level)) {
			if(now->R) ret+=now->R->v;
			ret+=ask(now->L,k,level-1);
		}
		else {
			if(now->L) ret+=now->L->v;
			ret+=ask(now->R,k,level-1);
		}
	}
	else {
		if(k&(1<<level)) {
			ret+=ask(now->R,k,level-1);
		}
		else {
			ret+=ask(now->L,k,level-1);
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) B[i+1]=B[i]^A[i];
	FOR(i,N+1) add(&head,B[i],30,1);
	
	ll ret=0;
	x=0;
	FOR(i,N) {
		add(&head,B[i],30,-1);
		ret+=ask(&head,x,30);
		x^=A[i];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

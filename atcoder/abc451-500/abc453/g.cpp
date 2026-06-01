#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M,Q;

template<class V> class PersistentSegTree_add {  //1点更新・区間和
public:
	V val;
	int L,R;
	PersistentSegTree_add *left, *right;

	PersistentSegTree_add(int L_,int R_,V v): L(L_),R(R_),val(v),left(NULL),right(NULL) {}
	PersistentSegTree_add(PersistentSegTree_add* p): L(p->L),R(p->R),val(p->val),left(p->left),right(p->right) {}
	V comp(V l,V r){ return l+r;}
	
	V getval(int x,int y) { // x<=i<y
		if(R<=x || y<=L) return 0;
		if(x<=L && R<=y) return val;
		V a=left?left->getval(x,y):0;
		V b=right?right->getval(x,y):0;
		
		return comp(a,b);
	}
	PersistentSegTree_add* update(int entry, V v) {
		PersistentSegTree_add* ret;
		if(L+1==R) {
			ret=new PersistentSegTree_add(L,R,v);
		}
		else {
			int M=(L+R)/2;
			ret=new PersistentSegTree_add(L,R,0);
			ret->left=left;
			ret->right=right;
			if(entry<M) {
				if(ret->left==NULL) ret->left=new PersistentSegTree_add(L,M,0);
				else ret->left=new PersistentSegTree_add(left);
				ret->left=ret->left->update(entry,v);
			}
			else {
				if(ret->right==NULL) ret->right=new PersistentSegTree_add(M,R,0);
				else ret->right=new PersistentSegTree_add(right);
				ret->right=ret->right->update(entry,v);
			}
			V a=ret->left?ret->left->val:0;
			V b=ret->right?ret->right->val:0;
			ret->val=comp(a,b);
		}
		return ret;
		
	}
};

PersistentSegTree_add<ll>* P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N+1) P[i]=new PersistentSegTree_add<ll>(0,1<<18,0);
	
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			P[x]=P[y];
		}
		else if(i==2) {
			cin>>x>>y>>k;
			P[x]=P[x]->update(y,k);
		}
		else {
			cin>>j>>x>>y;
			cout<<P[j]->getval(x,y+1)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

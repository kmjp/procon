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
			ret=new PersistentSegTree_add(L,R,comp(val,v));
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

const ll mo1=1000000007;
const ll mo2=998244353;
PersistentSegTree_add<ll>* root1,*PST1[101010];
PersistentSegTree_add<ll>* root2,*PST2[101010];
ll po[2][202020];


int N,Q;
int A[101010];
vector<int> E[101010];
int P[21][200005],D[200005];

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur,int pre) {
	if(cur==0) {
		PST1[cur]=root1->update(A[cur],po[0][A[cur]]);
		PST2[cur]=root2->update(A[cur],po[1][A[cur]]);
	}
	else {
		PST1[cur]=PST1[pre]->update(A[cur],po[0][A[cur]]);
		PST2[cur]=PST2[pre]->update(A[cur],po[1][A[cur]]);
		D[cur]=D[pre]+1;
		P[0][cur]=pre;
	}
	

	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
}

ll val(
	PersistentSegTree_add<ll>* a1,
	PersistentSegTree_add<ll>* a2,
	PersistentSegTree_add<ll>* a3,
	PersistentSegTree_add<ll>* a4
) {
	ll ret=0;
	if(a1) ret+=a1->val;
	if(a2) ret+=a2->val;
	if(a3) ret-=a3->val;
	if(a4) ret-=a4->val;
	return ret;
}

PersistentSegTree_add<ll>* LL(PersistentSegTree_add<ll>* cur) {
	if(cur) return cur->left;
	return NULL;
}
PersistentSegTree_add<ll>* RR(PersistentSegTree_add<ll>* cur) {
	if(cur) return cur->right;
	return NULL;
}



void dfs2(int L,int R,
	PersistentSegTree_add<ll>* p1a1,
	PersistentSegTree_add<ll>* p1a2,
	PersistentSegTree_add<ll>* p1a3,
	PersistentSegTree_add<ll>* p1a4,
	PersistentSegTree_add<ll>* p2a1,
	PersistentSegTree_add<ll>* p2a2,
	PersistentSegTree_add<ll>* p2a3,
	PersistentSegTree_add<ll>* p2a4,
	PersistentSegTree_add<ll>* p1b1,
	PersistentSegTree_add<ll>* p1b2,
	PersistentSegTree_add<ll>* p1b3,
	PersistentSegTree_add<ll>* p1b4,
	PersistentSegTree_add<ll>* p2b1,
	PersistentSegTree_add<ll>* p2b2,
	PersistentSegTree_add<ll>* p2b3,
	PersistentSegTree_add<ll>* p2b4,
	vector<int>& ret) {
	
	if(ret.size()>=10) return;
	ll a1=val(p1a1,p1a2,p1a3,p1a4);
	ll a2=val(p2a1,p2a2,p2a3,p2a4);
	ll b1=val(p1b1,p1b2,p1b3,p1b4);
	ll b2=val(p2b1,p2b2,p2b3,p2b4);
	if(a1==b1&&a2==b2) return;
	
	if(L+1==R) {
		ret.push_back(L);
	}
	else {
		dfs2(L,(L+R)/2,LL(p1a1),LL(p1a2),LL(p1a3),LL(p1a4),LL(p2a1),LL(p2a2),LL(p2a3),LL(p2a4),LL(p1b1),LL(p1b2),LL(p1b3),LL(p1b4),LL(p2b1),LL(p2b2),LL(p2b3),LL(p2b4),ret);
		dfs2((L+R)/2,R,RR(p1a1),RR(p1a2),RR(p1a3),RR(p1a4),RR(p2a1),RR(p2a2),RR(p2a3),RR(p2a4),RR(p1b1),RR(p1b2),RR(p1b3),RR(p1b4),RR(p2b1),RR(p2b2),RR(p2b3),RR(p2b4),ret);
	}
	
}
	


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	root1=new PersistentSegTree_add<ll>(0,1<<17,0);
	root2=new PersistentSegTree_add<ll>(0,1<<17,0);
	po[0][0]=po[1][0]=1;
	FOR(i,1<<17) {
		po[0][i+1]=po[0][i]*12345%mo1;
		po[1][i+1]=po[1][i]*123456%mo2;
	}
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	cin>>Q;
	while(Q--) {
		int u1,v1,u2,v2,k,lc1,lc2;
		cin>>u1>>v1>>u2>>v2>>k;
		u1--,v1--,u2--,v2--;
		lc1=lca(u1,v1);
		lc2=lca(u2,v2);
		vector<int> ret;
		
		dfs2(0,1<<17,PST1[u1],PST1[v1],PST1[lc1],(lc1)?PST1[P[0][lc1]]:NULL,
		     PST2[u1],PST2[v1],PST2[lc1],(lc1)?PST2[P[0][lc1]]:NULL,
		     PST1[u2],PST1[v2],PST1[lc2],(lc2)?PST1[P[0][lc2]]:NULL,
		     PST2[u2],PST2[v2],PST2[lc2],(lc2)?PST2[P[0][lc2]]:NULL,
		     ret);


		if(ret.size()>k) ret.resize(k);
		cout<<ret.size();
		FORR(r,ret) cout<<" "<<r;
		cout<<"\n";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

struct RBST* getent(struct RBST*);
RBST* deepcopy(RBST* n);
struct RBST {
	RBST *l,*r;
	ll v,sum,toadd;
	int cnt,rank;
	
	static int count(RBST* n){ return n?n->cnt:0;}
	static RBST* merge(RBST *ln,RBST *rn) {
		if(ln==NULL) return rn;
		if(rn==NULL) return ln;
		RBST* nt;
		if(rand()%(ln->cnt+rn->cnt) < ln->cnt) {
			ln->update();
			nt=deepcopy(ln);
			nt->r = merge(nt->r,rn);
		}
		else {
			rn->update();
			nt=deepcopy(rn);
			nt->l = merge(ln, nt->l);
		}
		return nt->update();
	}
	static RBST* merge(pair<RBST*,RBST*> p) { return merge(p.first,p.second);}
	
	pair<RBST*, RBST*> split(int k) {
		update();
		RBST* nt=deepcopy(this);
		if(k<=count(nt->l)) {
			pair<RBST*, RBST*> p=nt->l?nt->l->split(k):make_pair((RBST*)NULL,(RBST*)NULL);
			nt->l=p.second;
			return make_pair(p.first,nt->update());
		}
		else {
			pair<RBST*, RBST*> p=nt->r?nt->r->split(k-count(nt->l)-1):make_pair((RBST*)NULL,(RBST*)NULL);
			nt->r=p.first;
			return make_pair(nt->update(),p.second);
		}
	}
	
	RBST* update() {
		cnt=1;
		rank=0;
		sum=v;
		if(l) cnt+=count(l), sum+=l->sum, rank=max(rank,1+l->rank);
		if(r) cnt+=count(r), sum+=r->sum, rank=max(rank,1+r->rank);
		sum+=toadd*cnt;
		return this;
	}
	
	static RBST* deepcopy(RBST* n) {
		if(n==NULL) return NULL;
		
		n=getent(n);
		if(n->toadd) {
			if(n->l) {
				n->l=getent(n->l);
				n->l->toadd += n->toadd;
				n->l->update();
			}
			if(n->r) {
				n->r=getent(n->r);
				n->r->toadd += n->toadd;
				n->r->update();
			}
			n->v += n->toadd;
			n->toadd = 0;
		}
		return n->update();
	}
	
	RBST* add(int l,int r,ll v) {
		l=max(l,0);
		r=min(cnt,r);
		if(r-l<=0) return this;
		
		RBST* cl;
		if(l==0 && cnt==r) {
			cl = getent(this);
			cl->toadd += v;
		}
		else {
			cl = deepcopy(this);
			if(cl->l && l<cl->l->cnt) cl->l = cl->l->add(l,r,v);
			if(cl->r && count(cl->l)+1<r) cl->r = cl->r->add(l-(count(cl->l)+1),r-(count(cl->l)+1),v);
			if(l<=count(cl->l) && count(cl->l)+1<=r) cl->v+=v;
		}
		return cl->update();
	}
	ll getsum(int k) {
		if(k<=0) return 0;
		if(cnt<=k) return sum;
		
		ll ret=toadd*k;
		
		if(l) ret+=l->getsum(min(k,l->cnt)), k-=min(k,l->cnt);
		if(k) ret+=v, k--;
		if(k && r) ret+=r->getsum(min(k,r->cnt)), k-=min(k,r->cnt);
		assert(k==0);
		return ret;
	}
};

const int resv=15000000;
vector<RBST> mem;
RBST *top,*cur;
int N,Q;
ll X[300000];

RBST *getent(RBST* n){
	if(n==NULL) return NULL;
	mem.push_back(*n);
	return &mem.back();
}

void rebuild() {
	int i;
	
	mem.resize(N);
	top=NULL;
	FOR(i,N) {
		cur=&mem[i];
		cur->l=cur->r=NULL;
		cur->toadd=cur->sum=0;
		cur->v=X[i];
		cur->update();
		top=RBST::merge(top,cur);
	}
}

#include <sys/types.h>
#include <unistd.h>

void solve() {
	int i,j,k,l,r,x,y,a,b,c,d,v; string s;
	
	srand(time(NULL)+getpid());
	cin>>N>>Q;
	mem.reserve(resv);
	
	FOR(i,N) cin>>X[i];
	rebuild();
	
	pair<RBST*,RBST*> p1,p2;
	while(Q--) {
		cin>>i>>a>>b;
		
		if(i==1) {
			cin>>v;
			top=top->add(a-1,b,v);
		}
		else if(i==3) {
			cout<<top->getsum(b)-top->getsum(a-1)<<endl;
		}
		else if(i==2) {
			cin>>c>>d;
			p2=top->split(d);
			p1=p2.first->split(c-1);
			cur=RBST::deepcopy(p1.second);
			top=RBST::merge(getent(p1.first),getent(p1.second));
			top=RBST::merge(getent(top),getent(p2.second));
			
			p2=top->split(b);
			p1=p2.first->split(a-1);
			top=RBST::merge(getent(p1.first),cur);
			top=RBST::merge(getent(top),getent(p2.second));
		}
		// GC?
		if(mem.size()>resv*9/10) {
			FOR(i,N) X[i]=top->getsum(i+1)-top->getsum(i);
			rebuild();
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

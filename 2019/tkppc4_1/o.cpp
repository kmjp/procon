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

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return ret*mul[k]+add[k]*(y-x);
	}
	void propagate(int k,int s) {
		mul[k*2]*=mul[k];
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		add[k*2]+=add[k];
		sum[k*2]+=add[k]*s/2;
		mul[k*2+1]*=mul[k];
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		add[k*2+1]+=add[k];
		sum[k*2+1]+=add[k]*s/2;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mul[k]*=v;
			add[k]*=v;
			sum[k]*=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum[k]+=(r-l)*v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
};

SegTree_MulAdd<ll, 1<<18> P,Q;



int N;
int A[101010],B[101010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> As;
	As.push_back(0);
	FOR(i,N) {
		cin>>A[i];
		As.push_back(A[i]);
	}
	FOR(i,N) {
		cin>>B[i];
	}
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	
	FOR(i,N) {
		x=lower_bound(ALL(As),A[i])-As.begin();
		
		ll cur=P.getval(x,x+1)*As[x]+Q.getval(x,x+1)+B[i];
		int t=x;
		for(j=17;j>=0;j--) if(t+(1<<j)<As.size()) {
			ll ct=P.getval(t+(1<<j),t+(1<<j)+1)*As[t+(1<<j)]+Q.getval(t+(1<<j),t+(1<<j)+1);
			if(ct<=cur) t+=1<<j;
		}
		
		P.doadd(0,x,1);
		Q.doadd(0,x,-A[i]+B[i]);
		P.domul(x,t+1,0);
		Q.domul(x,t+1,0);
		Q.doadd(x,t+1,cur);
		
		/*
		FOR(j,As.size()) cout<<P.getval(j,j+1)*As[j]+Q.getval(j,j+1)<<" ";
		cout<<endl;
		*/
		
	}
	ll ret=0;
	FOR(i,As.size()) {
		ret=max(ret,P.getval(i,i+1)*As[i]+Q.getval(i,i+1));
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

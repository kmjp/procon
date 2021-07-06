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

template<typename ST=vector<int>>
struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; ST S;

	void build(ST S) {
		this->S=S;
		int i,h=0; vector<int> tmp;
		N=S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
		FOR(i,N+1) sa[i]=i, rank[i]=i==N?-1:S[i];
		
		for(int k=1; k<=N; k<<=1) {
			auto pred2 = [k,this](int& a,int &b)->bool{ return (((a+k<=N)?rank[a+k]:-1)<((b+k<=N)?rank[b+k]:-1));};
			auto pred = [pred2,k,this](int& a,int &b)->bool{ return (rank[a]!=rank[b])?(rank[a]<rank[b]):pred2(a,b);};
			int x=0;
			if(k!=1) for(i=1;i<N+1;i++) if(rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x=i;
			sort(sa.begin()+x,sa.end(),pred);
			FOR(i,N+1) tmp[sa[i]]=(i==0)?0:tmp[sa[i-1]]+pred(sa[i-1],sa[i]);
			swap(rank,tmp);
		}
		lcp.resize(N+1); rsa.resize(N+1);
		FOR(i,N+1) rsa[sa[i]]=i;
		FOR(i,N) {
			int j=sa[rsa[i]-1];
			for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
			lcp[rsa[i]-1]=h;
		}
	}
};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,0);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<18> st;

int rev[201010];
vector<int> cand[101010];
SuffixArray sa;
vector<int> R;
class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
		int m=paths.size();
		R.clear();
		
		int i,j,x;
		FOR(i,m) {
			FOR(j,paths[i].size()) {
				rev[R.size()]=i;
				R.push_back(paths[i][j]);
			}
			rev[R.size()]=-1;
			R.push_back(1000000+i);
			cand[i].clear();
		}
		rev[R.size()]=-1;
		sa.build(R);
		FOR(i,R.size()) {
			st.update(i,sa.lcp[i]);
			x=sa.sa[i];
			if(rev[x]>=0) cand[rev[x]].push_back(i);
		}
		set<int> nexts;
		FOR(i,m) {
			cand[i].push_back(R.size());
			reverse(ALL(cand[i]));
			nexts.insert(cand[i].back());
		}
		
		int ma=0;
		FOR(i,R.size()) {
			int nex=*nexts.rbegin();
			if(nex==R.size()) break;
			x=sa.sa[i];
			if(rev[x]<0) continue;
			ma=max(ma,st.getval(i,nex));
			nexts.erase(i);
			cand[rev[x]].pop_back();
			nexts.insert(cand[rev[x]].back());
		}
		
		
		return ma;
        
    }
};


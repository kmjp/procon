
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

struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; string S;
	
	SuffixArray(string S) : S(S){
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


class Solution {
public:

    string lastSubstring(string s) {
		SuffixArray sa(s);
		return s.substr(sa.sa[s.size()]);
        
    }
};


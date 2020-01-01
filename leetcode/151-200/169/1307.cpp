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
class Solution {
public:
	int num[256]={},top[256]={};
	bool dfs(string& V,int mask,int v) {
		int b=__builtin_popcount(mask);
		if(b==10) return v==0;
		int i;
		FOR(i,10) if((mask&(1<<i))==0) {
			if(mask==0 && top[V[i]]) continue;
			if(dfs(V,mask|(1<<i),v+b*num[V[i]])) return true;
		}
		return false;
	}
    bool isSolvable(vector<string>& words, string result) {
		ZERO(num);
		ZERO(top);
        string V;
        FORR(w,words) {
			if(w.size()>1) top[w[0]]=1;
			reverse(ALL(w));
			int p=1;
			FORR(c,w) {
				V.push_back(c);
				num[c]+=p;
				p*=10;
			}
		}
		int p=1;
		if(result.size()>1) top[result[0]]=1;
		reverse(ALL(result));
        FORR(c,result) {
			V.push_back(c);
			num[c]-=p;
			p*=10;
		}
		
        sort(ALL(V));
        V.erase(unique(ALL(V)),V.end());
        int i;
        FOR(i,10) if(V.size()<10) V.push_back('a'+i);
        sort(ALL(V));
        
		return dfs(V,0,0);
        
        
        
    }
};

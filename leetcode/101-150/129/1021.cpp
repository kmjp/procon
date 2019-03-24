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
    bool queryString(string S, int N) {
		set<ll> cand;
		int i;
		FOR(i,S.size()) if(S[i]=='1') {
			ll cur=0;
			for(int j=i;j<S.size();j++) {
				cur=cur*2+S[j]-'0';
				cand.insert(cur);
				if(cur>1<<30) break;
			}
		}
		
		for(int i=1;i<=N;i++) {
			if(cand.count(i)==0) return false;
		}
		return true;
		
        
    }
};



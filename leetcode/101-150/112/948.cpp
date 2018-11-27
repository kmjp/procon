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
    int bagOfTokensScore(vector<int>& tokens, int P) {
		int N=tokens.size();
		sort(ALL(tokens));
		if(tokens.empty()) return 0;
		
		int ma=0;
		for(int sell=0;sell*2<=N;sell++) {
			int i;
			int cur=P;
			FOR(i,sell) {
				cur-=tokens[i];
				if(cur<0) break;
				cur+=tokens[N-1-i];
			}
			if(i<sell) continue;
			
			int num=0;
			for(i=sell;i<N-sell;i++) {
				cur-=tokens[i];
				if(cur<0) break;
				num++;
				ma=max(ma,num);
			}
			
		}
		return ma;
    }
};

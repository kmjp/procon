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
    int maxScore(vector<int>& cardPoints, int k) {
		int ma=0;
		int i,j;
		int cur=0;
		FOR(i,k) cur+=cardPoints[i];
		ma=cur;
		for(i=0,j=k-1;j>=0,i<k;i++,j--) {
			cur-=cardPoints[j];
			cur+=cardPoints[cardPoints.size()-1-i];
			ma=max(ma,cur);
		}
		return ma;
			
        
    }
};



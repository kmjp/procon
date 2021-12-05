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
    vector<int> findEvenNumbers(vector<int>& digits) {
		set<int> S;
		int x,y,z;
		int C[10]={};
		FORR(c,digits) C[c]=min(3,C[c]+1);
		digits.clear();
		FOR(x,10) FOR(y,C[x]) digits.push_back(x);
		sort(ALL(digits));
		FOR(z,digits.size()) FOR(y,z) FOR(x,y) {
			S.insert(digits[z]*100+digits[y]*10+digits[x]);
			S.insert(digits[z]*100+digits[x]*10+digits[y]);
			S.insert(digits[y]*100+digits[x]*10+digits[z]);
			S.insert(digits[y]*100+digits[z]*10+digits[x]);
			S.insert(digits[x]*100+digits[y]*10+digits[z]);
			S.insert(digits[x]*100+digits[z]*10+digits[y]);
		}
		
		vector<int> F;
		FORR(s,S) {
			if(s>=100&&s%2==0) F.push_back(s);
		}
		return F;
        
    }
};

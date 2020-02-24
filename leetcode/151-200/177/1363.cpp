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
    string largestMultipleOfThree(vector<int>& digits) {
		string S[3];
		int num=0;
		FORR(d,digits) {
			num+=d;
			S[d%3]+='0'+d;
		}
		int i;
		FOR(i,3) {
			sort(ALL(S[i]));
			reverse(ALL(S[i]));
		}
		
		if(num%3==1) {
			if(S[1].size()) {
				S[1].pop_back();
			}
			else {
				S[2].pop_back();
				S[2].pop_back();
			}
		}
		else if(num%3==2) {
			if(S[2].size()) {
				S[2].pop_back();
			}
			else {
				S[1].pop_back();
				S[1].pop_back();
			}
		}
		string R=S[0]+S[1]+S[2];
		sort(ALL(R));
		if(R.size()&&R.back()=='0') return "0";
		reverse(ALL(R));
		return R;
    }
};

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


string incinc(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r=='1') r='0';
		else {
			r++;
			break;
		}
	}
	if(A.back()=='0') A += '1';
	reverse(A.begin(),A.end());
	return A;
}

class Solution {
public:
    int numSteps(string s) {
		
		int step=0;
		while(s!="1") {
			if(s.back()=='0') {
				step++;
				s.pop_back();
			}
			else {
				step++;
				s=incinc(s);
			}
			
		}
		return step;
    }
};


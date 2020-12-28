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
    bool halvesAreAlike(string s) {
		string a=s.substr(0,s.size()/2);
		string b=s.substr(s.size()/2);
		int C=0,D=0;
		FORR(c,a) {
			if(c=='a') C++;
			if(c=='i') C++;
			if(c=='u') C++;
			if(c=='e') C++;
			if(c=='o') C++;
			if(c=='A') C++;
			if(c=='I') C++;
			if(c=='U') C++;
			if(c=='E') C++;
			if(c=='O') C++;
		}
		FORR(c,b) {
			if(c=='a') D++;
			if(c=='i') D++;
			if(c=='u') D++;
			if(c=='e') D++;
			if(c=='o') D++;
			if(c=='A') D++;
			if(c=='I') D++;
			if(c=='U') D++;
			if(c=='E') D++;
			if(c=='O') D++;
		}
		return C==D;
        
    }
};


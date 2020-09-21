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
    string reorderSpaces(string text) {
		vector<string> S;
		S.push_back("");
		int s=0;
		FORR(c,text) {
			if(c==' ') {
				s++;
				if(S.back()!="") S.push_back("");
			}
			else {
				S.back()+=c;
			}
		}
		if(S.back()=="") S.pop_back();
		
		cout<<s<<endl;
		string T;
		if(S.size()==1) {
			T=S[0];
		}
		else {
			int sp=S.size()-1;
			int hoge=s/sp;
			int i,j;
			FOR(j,S.size()) {
				T+=S[j];
				if(j!=S.size()-1) {
					FOR(i,hoge) {
						T+=" ";
						s--;
					}
				}
			}
			
		}
		while(s--) T+=" ";
		return T;
		
        
    }
};




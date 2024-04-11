
// min bars to split the word so that all the splitted word present in given list of words


#include<iostream>
#include<map>
#include<unordered_set>
#include<climits>
#include<vector>

using namespace std;


string s ="thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the","fox","thequickbrownfox", "jumps","lazy","lazyfox",

					"highbridge","the","over", "bridge","high","tall",

					"quick","brown"};

/*
string s ="thequickbrownfox";

string words[] = {"the", "quickbrown", "fox","quick","brown"};
*/

int minBarsRec(string str, unordered_set<string> st, int idx) {
    if(idx >= str.length()) {
        return 0;
    }
    int ans = INT_MAX;
    string current_string = "";

    for(int i = idx; i < str.size(); i++) {
        current_string += str[i];
        if(st.find(current_string) != st.end()) {
            int remaining_ans = minBarsRec(str, st, i+1);
            if(remaining_ans != -1) {
                ans = min(ans, 1+remaining_ans);
            }
        }
    }

    if(ans == INT_MAX) {
        return -1;
    }
    return ans;



}

void minBars() {
    
    unordered_set<string> st;
    for(auto x: words) {
        st.insert(x);
    }
    int ans = minBarsRec(s, st, 0);
    cout << ans-1 << endl;

}

int main() {
    minBars();

    return 0;
}
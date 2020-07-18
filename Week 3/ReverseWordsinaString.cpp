/*
Given an input string, reverse the string word by word.
Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(),s.end());
    string res="";
    //cout<<s;
    string temp="";
    for(int i=0;i<=s.length();i++){
      if(s[i]==' ' && temp=="") continue;
      else if((i==s.length()||s[i]==' ') && temp!=""){
        res+=temp+" ";
        temp="";
      }
      else temp=s[i]+temp;
    }
    cout<<res;
    return res.substr(0,res.length()-1);
}
};

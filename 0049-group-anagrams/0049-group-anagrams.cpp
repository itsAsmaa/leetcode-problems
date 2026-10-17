#include <vector>
#include<string>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string , vector<string>> groups; //label -> list of words

       for (string word : strs){
        string label = word;//copy the word
        sort(label.begin() , label.end());// sort letters: "tea" -> "aet"
        groups[label].push_back(word); // put word in its group

       }
       
       vector<vector<string>> result ;
       for (auto group : groups){//go through each group
           result.push_back(group.second);//add its list of words
       }
       return result;
       
    }
};
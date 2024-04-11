class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[26] = {0};
        int max_length = 0;
        int length = 0, space_count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){ // Check for whitespace instead of '0'
                if(space_count == 0){
                    length++;
                    space_count++;
                    continue;
                } else {
                    length = 1;
                    max_length = max(max_length, length);
                    space_count++;
                }
            }
            else if(s[i] != ' ' && arr[s[i] - 'a'] < 1){
                arr[s[i] - 'a']++;
                length++;
            } else {
                arr[s[i] - 'a'] = 0;
                i = 
                max_length = max(max_length, length);
                length = 1;
            }
        }
        return max(max_length, length); // Return the final maximum length
    }
};
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
            letters.push_back(target);
            sort(letters.begin(), letters.end());
            letters.erase(unique(letters.begin(), letters.end()), letters.end());
            vector<char>::iterator iter = find(letters.begin(), letters.end(), target);
            int pos = iter-letters.begin();
            if(pos == letters.size()-1)
            {
                return letters[0];
            }
            else
            {
                return letters[pos+1];
            }
    }
};

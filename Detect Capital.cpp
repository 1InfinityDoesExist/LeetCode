class Solution {
public:
    bool detectCapitalUse(string word) {
        int sz = word.length();
        int count (0);
        int cnt (0);

        if(sz == 1)
        {
            return true;
        }

        if(isupper(word[0]))
        {
            if(isupper(word[1]))
            {
                for(string::size_type iter = 2; iter < sz; iter++)
                {
                    if(isupper(word[iter]))
                    {
                        count++;
                    }
                }
                 if(count == sz-2)
                 {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if(islower(word[1]))
            {
                  for(string::size_type iter = 2; iter < sz; iter++)
                   {
                       if(islower(word[iter]))
                        {
                            count++;
                        }
                    }
                 if(count == sz-2)
                 {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }



       else
       {
            for(string::size_type iter = 1; iter < sz; iter++)
            {
                if(islower(word[iter]))
                {
                    count++;
                }
            }
           if(count == sz-1)
           {
               return true;
           }
           else
           {
               return false;
           }
       }

    }
};

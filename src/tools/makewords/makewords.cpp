#include "makewords.h"

int main()
{
    try
    {
        TextDB db("dict.txt");
        ifstream ifs("../../../res/1w9.txt", ios_base::in);
        string s;
        while (getline(ifs, s))
        {
            stringstream ss;
            size_t index = s.find('|');
            string word = s.substr(0, index);
            string desc = s.substr(index + 1);
            cout << word << endl;
            auto &vec = db[word];
            for (size_t i = 0; i < desc.length(); ++i)
            {
                auto isPOSChar = [] (char ch)
                {
                    return ch >= 'a' && ch <= 'z';
                };
                bool isPOS = i > 0 && isPOSChar(desc[i]) && !isPOSChar(desc[i - 1]);
                
                if (isPOS) // further check
                {
                    isPOS = false;
                    for (size_t j = i; j < desc.length(); ++j)
                    {
                        if (desc[j] == '.')
                        {
                            isPOS = true;
                            break;
                        }
                        else if (!isPOSChar(desc[j]))
                        {
                            break;
                        }
                    }
                }
                
                if (isPOS)
                {
                    if (ss.str() != "")
                    {
                        vec.push_back(ss.str());
                    }
                    ss.str("");
                }
                ss << desc[i];
            }
            if (ss.str() != "")
            {
                vec.push_back(ss.str());
            }
        }
    }
    catch (SyntaxError err)
    {
        cerr << err.what << endl;
    }
    return 0;
}
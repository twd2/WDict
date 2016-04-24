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
                if (i > 0 && (desc[i] >= 'a' && desc[i] <= 'z') && !(desc[i - 1] >= 'a' && desc[i - 1] <= 'z'))
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
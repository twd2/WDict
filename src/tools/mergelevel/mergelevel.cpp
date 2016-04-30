#include "mergelevel.h"

int main()
{
    try
    {
        TextDB in1("iciba_level.txt");
        TextDB in2("dictcn_level.txt");
        TextDB out("level.txt");
        for (auto iter = in1.begin(); iter != in1.end(); ++iter)
        {
            int a = -1, b = -1;
            
            auto &veca = iter->second, &vecb = in2[iter->first];
            
            if (veca.size() == 0 || veca[0] == "" || veca[0] == "None")
            {
                a = -1;
            }
            else
            {
                a = StringUtils::FromString<int>(veca[0]);
            }
            
            if (vecb.size() == 0 || vecb[0] == "" || vecb[0] == "None")
            {
                b = -1;
            }
            else
            {
                b = StringUtils::FromString<int>(vecb[0]);
            }
            
            if (a == -1 && b == -1)            
            {
                out[iter->first].push_back("-1");
            }
            else if (a == -1 && b >= 0)
            {
                out[iter->first].push_back(StringUtils::ToString(b));
            }
            else if (a >= 0 && b == -1)
            {
                out[iter->first].push_back(StringUtils::ToString(a));
            }
            else
            {
                out[iter->first].push_back(StringUtils::ToString((a + b) / 2));
            }
        }
    }
    catch (SyntaxError err)
    {
        cerr << err.what << endl;
    }
    return 0;
}
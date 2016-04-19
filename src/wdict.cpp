#include "wdict.h"

int main()
{
    try
    {
        TextDB db("dict.txt");
        /*ifstream ifs("dict.txt", ios_base::in);
        string s = FileUtils::ReadAllText(static_cast<istream&>(ifs));
        
        if (s == "")
        {
            return 1;
        }
        
        Lexer lex(s);
        
        auto tokens = lex.Do();
        
        for (Token tok : tokens)
        {
            cout << Token::Name(tok.Type) << " " << StringUtils::Unescape(tok.Value) << endl;
        }
        cout << endl;*/
    }
    catch (SyntaxError err)
    {
        cerr << err.what << endl;
    }
    
    /*string s;
    while (getline(cin, s))
    {
        cout << StringUtils::Escape(s) << " " << (StringUtils::Unescape(StringUtils::Escape(s)) == s) << endl;
    }*/
    return 0;
}
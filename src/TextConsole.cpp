#include "TextConsole.h"

bool TextConsole::Show()
{
    if (filename == "")
    {
        txtFilename.Show();
        if (txtFilename.Value != "")
        {
            ifstream ifs(txtFilename.Value, ios_base::in);
            Words = StringUtils::GetWords(FileUtils::ReadAllText(ifs), true);
            ifs.close();
            filename = txtFilename.Value;
        }
        else
        {
            Root.Back();
            return true;
        }
    }
       
    for (string word : Words)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << "共" << Words.size() << "个不同的单词。" << endl;
    
    // TODO: auto display words that the user do not know
    
    txtWord.Show();
    if (txtWord.Value != "")
    {
        Globals::CurrentUser->AppendHistory(txtWord.Value);
        Root.Goto(make_shared<WithTitleConsole>(txtWord.Value, make_shared<WordConsole>(Root, txtWord.Value)));
    }
    else
    {
        Root.Back();
    }
    
    return true;
}
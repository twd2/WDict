#include "TextConsole.h"

bool TextConsole::Show()
{
    if (filename == "")
    {
        txtFilename.Show();
        
        if (txtFilename.Value != "")
        {
            if (txtFilename.Value[0] == '\'' && txtFilename.Value.size() > 2)
            {
                txtFilename.Value = txtFilename.Value.substr(1, txtFilename.Value.size() - 2);
            }
            cout << txtFilename.Value << endl;
            
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
    
    size_t counter = 0;
    for (string word : Words)
    {
        if (!Globals::CurrentUser->WordEvaluate->IsKnown(word))
        {
            cout << word << endl;
            WordInfo wi = Globals::Dict->GetWord(word);
            if (wi.Desc.size() > 0)
            {
                for (string desc : wi.Desc)
                {
                    cout << "    " << desc << endl;
                }
            }
            else
            {
                cout << "    *未找到释义*" << endl;
            }
        }
        ++counter;
    }
    cout << endl;
    
    cout << "共" << Words.size() << "个不同的单词，显示了" << counter << "个释义。" << endl;
    
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
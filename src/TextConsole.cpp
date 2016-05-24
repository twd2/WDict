#include "TextConsole.h"

TextConsole::TextConsole(Console &Root)
    : ConsoleComponent(Root), txtFilename(Root, "请输入要分析的文本的路径(可将文件拖入控制台来获得文件路径，输入空行返回):", TEXTINPUT_LINE),
                                  txtWord(Root, "请输入要查询的单词(输入空行返回):", TEXTINPUT_LINE)
{

}

bool TextConsole::Show()
{
    WithTitleConsole(Root, "文本分析").Show();
    
    if (filename == "")
    {
        txtFilename.Show();
        
        if (txtFilename.Value != "")
        {
            if (txtFilename.Value[0] == '\'' && txtFilename.Value.size() > 2)
            {
                txtFilename.Value = txtFilename.Value.substr(1, txtFilename.Value.size() - 2);
            }
            outs << txtFilename.Value << endl;
            
            ifstream ifs(txtFilename.Value, ios_base::in);
            Words = DictStringUtils::GetWords(FileUtils::ReadAllText(ifs), true);
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
        if (!Globals::CurrentUser->WordEvaluator->IsKnown(word))
        {
            outs << word << endl;
            WordInfo wi = Globals::Dict->GetWord(word);
            if (wi.Desc.size() > 0)
            {
                for (string desc : wi.Desc)
                {
                    outs << "    " << desc << endl;
                }
            }
            else
            {
                outs << "    *未找到释义*" << endl;
            }
            ++counter;
        }
    }
    outs << endl;
    
    outs << "共" << Words.size() << "个不同的单词，显示了" << counter << "个生词释义。" << endl;
    
    txtWord.Show();
    if (txtWord.Value != "")
    {
        Globals::CurrentUser->AppendHistory(txtWord.Value);
        Root.Goto(make_shared<WordConsole>(Root, txtWord.Value));
    }
    else
    {
        Root.Back();
    }
    
    return true;
}

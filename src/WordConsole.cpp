#include "WordConsole.h"
#include <typeinfo>

WordConsole::WordConsole(Console &Root, const string &Word)
    : ConsoleComponent(Root), btnAddDesc(Root, '1', "添加释义"), btnAddSent(Root, '2', "添加例句"),
                              btnDelDesc(Root, '3', "删除释义"), btnDelSent(Root, '4', "删除例句"),
                              btnSearch(Root, 's', "搜索"), btnReport(Root, 'r', "报告错误"), btnBack(Root, 'b', "返回"), Word(Word)
{
    btnAddDesc.OnClick = bind(&WordConsole::AddDesc, this);
    Add(btnAddDesc);
    
    btnAddSent.OnClick = bind(&WordConsole::AddSent, this);
    Add(btnAddSent);
    
    btnDelDesc.OnClick = bind(&WordConsole::DelDesc, this);
    Add(btnDelDesc);
    
    btnDelSent.OnClick = bind(&WordConsole::DelSent, this);
    Add(btnDelSent);
    
    btnSearch.OnClick = bind(&WordConsole::Search, this);
    Add(btnSearch);
    
    btnReport.OnClick = bind(&WordConsole::Report, this);
    Add(btnReport);
    
    btnBack.OnClick = bind(&WordConsole::Back, this);
    Add(btnBack);
}

void WordConsole::PrintWord(ostream &outs, const string &str, WordInfo wi)
{
    if (wi.Desc.size() > 0)
    {
        outs << str + "释义:" << endl;
        size_t i = 0;
        for (string desc : wi.Desc)
        {
            outs << "    " << ++i << ". " << desc << endl;
        }
    }
    else
    {
        outs << string("未找到") + str + "释义。" << endl;
    }
    outs << endl;
    
    if (wi.Sentences.size() > 0)
    {
        outs << str + "例句:" << endl;
        size_t i = 0;
        for (auto p : wi.Sentences)
        {
            outs << "  " << ++i << ". " << p.first << endl
                 << "    " << p.second << endl
                 << endl;
        }
    }
    else
    {
        outs << string("未找到") + str + "例句。" << endl;
    }
    outs << endl;
}

bool WordConsole::Show()
{
    WithTitleConsole(Root, Word).Show();
    
    bool found = Globals::Dict->GetWord(Word).Desc.size() != 0 || Globals::CurrentUser->GetWord(Word).Desc.size() != 0;
    auto related = Globals::Dict->GetRelated(Word, 20);
    
    if (!found) // no system or user desc
    {
        outs << "没有找到这个单词, 您可以添加释义或者尝试查询以下单词: " << endl;
        
        for (auto w : related)
        {
            outs << w << " ";
        }
        outs << endl;
        outs << string(80, '-') << endl;
    }
    else
    {
        auto &evalPtr = Globals::CurrentUser->WordEvaluator;
        bool haveFlags = false;
        
        if (evalPtr->IsCommon(Word))
        {
            outs << "*常见词*    ";
            haveFlags = true;
        }
        else
        {
            outs << "*生僻词*    ";
            haveFlags = true;
        }
        
        if (evalPtr->IsForgettable(Word))
        {
            outs << "*您容易忘记*    ";
            haveFlags = true;
        }
        
        if (evalPtr->IsKnown(Word))
        {
            outs << "*熟词*    ";
            haveFlags = true;
        }
        else
        {
            outs << "*生词*    ";
            haveFlags = true;
        }
        
        if (haveFlags)
        {
            outs << endl;
        }
        
        outs << string(80, '-') << endl;
    }
    
    PrintWord(outs, "系统", Globals::Dict->GetWord(Word));
    PrintWord(outs, "您添加的", Globals::CurrentUser->GetWord(Word));
    
    if (found)
    {
        outs << "易混淆单词: " << endl;
        
        for (auto w : related)
        {
            outs << w << " ";
        }
        outs << endl;
    }
    
    ShowSubComponents();
    DoButtons();

    return true;
}

void WordConsole::AddDesc()
{
    TextInputConsole txtDesc(Root, "释义:", TEXTINPUT_LINE);
    txtDesc.Show();
    if (txtDesc.Value != "")
    {
        Globals::CurrentUser->AddDesc(Word, txtDesc.Value);
        Globals::UserDictDB->Sync();
    }
}

void WordConsole::AddSent()
{
    TextInputConsole txtSent(Root, "例句:", TEXTINPUT_LINE);
    txtSent.Show();
    if (txtSent.Value != "")
    {
        TextInputConsole txtDesc(Root, "释义:", TEXTINPUT_LINE);
        txtDesc.Show();
        Globals::CurrentUser->AddSentence(Word, txtSent.Value, txtDesc.Value);
        Globals::UserSentDB->Sync();
    }
}

void WordConsole::DelDesc()
{
    TextInputConsole txtId(Root, "请输入编号:", TEXTINPUT_LINE);
    txtId.Show();
    if (txtId.Value != "")
    {
        size_t id = StringUtils::FromString<size_t>(txtId.Value);
        if (txtId.Value != StringUtils::ToString(id))
        {
            // is not number
            return;
        }
        
        ConfirmConsole cc(Root, "您确定要删除吗?", false);
        cc.Show();
        if (cc.Value)
        {
            Globals::CurrentUser->DelDesc(Word, id - 1);
            Globals::UserDictDB->Sync();
        }
    }
}

void WordConsole::DelSent()
{
    TextInputConsole txtId(Root, "请输入编号:", TEXTINPUT_LINE);
    txtId.Show();
    if (txtId.Value != "")
    {
        size_t id = StringUtils::FromString<size_t>(txtId.Value);
        if (txtId.Value != StringUtils::ToString(id))
        {
            // is not number
            return;
        }
        
        ConfirmConsole cc(Root, "您确定要删除吗?", false);
        cc.Show();
        if (cc.Value)
        {
            Globals::CurrentUser->DelSentence(Word, id - 1);
            Globals::UserSentDB->Sync();
        }
    }
}

void WordConsole::Back()
{
    Root.Back();
}

void WordConsole::Search()
{
    Globals::Open(string("http://www.gglink.pw/search?site=&source=hp&btnG=Google+%E6%90%9C%E7%B4%A2&q=") + Word);
}

void WordConsole::Report()
{
    Globals::Open("https://github.com/twd2/WDict/issues/new");
}

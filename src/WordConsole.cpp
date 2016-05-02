#include "WordConsole.h"
#include <typeinfo>

WordConsole::WordConsole(Console &Root, const string &Word)
    : ConsoleComponent(Root), btnAddDesc(Root, '0', "添加释义"), btnAddSent(Root, '1', "添加例句"),
                              btnDelDesc(Root, '2', "删除释义"), btnDelSent(Root, '3', "删除例句"),
                              btnSearch(Root, '4', "搜索"), btnBack(Root, 'b', "返回"), Word(Word)
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
    
    btnBack.OnClick = bind(&WordConsole::Back, this);
    Add(btnBack);
}

void WordConsole::PrintWord(const string &str, WordInfo wi)
{
    if (wi.Desc.size() > 0)
    {
        cout << str + "释义:" << endl;
        size_t i = 0;
        for (string desc : wi.Desc)
        {
            cout << "    " << i++ << ". " << desc << endl;
        }
    }
    else
    {
        cout << string("未找到") + str + "释义。" << endl;
    }
    cout << endl;
    
    if (wi.Sentences.size() > 0)
    {
        cout << str + "例句:" << endl;
        size_t i = 0;
        for (auto p : wi.Sentences)
        {
            cout << "  " << i++ << ". " << p.first << endl
                 << "    " << p.second << endl
                 << endl;
        }
    }
    else
    {
        cout << string("未找到") + str + "例句。" << endl;
    }
    cout << endl;
}

bool WordConsole::Show()
{
    auto &evalPtr = Globals::CurrentUser->WordEvaluate;
    bool haveFlags = false;
    
    if (evalPtr->IsCommon(Word))
    {
        cout << "*常见词*    ";
        haveFlags = true;
    }
    else
    {
        cout << "*生僻词*    ";
        haveFlags = true;
    }
    
    if (evalPtr->IsForgettable(Word))
    {
        cout << "*您容易忘记*    ";
        haveFlags = true;
    }
    
    if (evalPtr->IsKnown(Word))
    {
        cout << "*熟词*    ";
        haveFlags = true;
    }
    else
    {
        cout << "*生词*    ";
        haveFlags = true;
    }
    
    if (haveFlags)
    {
        cout << endl;
    }
    
    cout << string(80, '-') << endl;
    
    PrintWord("系统", Globals::Dict->GetWord(Word));
    PrintWord("您添加的", Globals::CurrentUser->GetWord(Word));
    
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
            Globals::CurrentUser->DelDesc(Word, id);
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
            Globals::CurrentUser->DelSentence(Word, id);
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
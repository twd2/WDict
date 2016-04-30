#include "UI.h"

std::shared_ptr<UIImpl> UI::ui;

void UI::Init(std::shared_ptr<UIImpl> ui)
{
    UI::ui = ui;
}

void UI::Start()
{
    if (!ui)
    {
        throw std::string("UI is not initialized.");
    }
    while (ui->Show());
#ifdef DEBUG
    std::cout << "UI exited" << std::endl;
#endif
}
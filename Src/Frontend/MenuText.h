#include "MenuEntry.h"

class MenuText : public MenuEntry {
public:
MenuText(const std::string& text) : m_text(text)
{}

void update() override;

void draw() override;

void select() override;

void focus(bool hasFocus) override;

bool addChildMenu(std::shared_ptr<MenuEntry>) override;

bool removeChildMenu(std::shared_ptr<MenuEntry>) override;

private:
	std::string m_text;
	bool m_isFocused;

};

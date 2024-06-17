#include "MenuEntry.h"

class MenuButton : public MenuEntry {
public:
	MenuButton(const std::function<void()>& onClick) : m_onClick(onClick)
	{}
	
	void update() override;
	void draw() override;
	void select() override;
	void focus(bool hasFocus) override;
	void onClick();

	bool addChildMenu(std::shared_ptr<MenuEntry>) override;
	bool removeChildMenu(std::shared_ptr<MenuEntry>) override;



private:	
	std::function<void()> m_onClick;
	bool m_isFocused;
	
};

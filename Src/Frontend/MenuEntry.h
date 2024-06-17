#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>


class MenuEntry{
public:
	virtual ~MenuEntry() = default;
    virtual void update() = 0;
    virtual void draw() = 0;
	virtual void select() = 0;
	virtual void focus(bool hasFocus) = 0;
    virtual bool addChildMenu(std::shared_ptr<MenuEntry> childMenu) = 0;
    virtual bool removeChildMenu(std::shared_ptr<MenuEntry> childMenu) = 0;

};

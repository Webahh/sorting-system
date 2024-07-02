#pragma once
#include <Frontend/EventReceiver.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>

namespace so {

	class Display;

	class MenuEntry : public EventReceiver{
	public:

		MenuEntry()
		{
		}

		virtual ~MenuEntry() = default;

		virtual void update(){
			if(m_onUpdateFunc)
				m_onUpdateFunc();
		}

		virtual std::string draw() = 0;

		void setOnUpdate(const std::function<void()>& onUpdateFunc){
			m_onUpdateFunc = onUpdateFunc;
		}

	private:
		std::function<void()> m_onUpdateFunc;
	};

	template<typename T>
	class MenuBuilderBase{
	public:
		MenuBuilderBase()
			: m_obj(std::make_shared<T>())
		{

		}

		MenuBuilderBase assign(std::shared_ptr<T>& memberPtr){
			memberPtr = m_obj;
			return *this;
		}

		std::shared_ptr<T> build(){
			return m_obj;
		}

	protected:
		T& get(){
			return *m_obj;
		}

	private:
		std::shared_ptr<T> m_obj;
	};

	template<typename T>
	class MenuBuilder : public  MenuBuilderBase<T>{};
}



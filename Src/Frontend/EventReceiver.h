#pragma once

#include <string>
#include <memory>
#include <functional>
#include <map>

#define BIND_EVENT(key, event) {key, std::bind(event, this)}

namespace so{
	typedef std::string EventType;

	class EventReceiver {
	public:
		typedef std::map<EventType, std::function<void()>> EventReceiverMappings;

		void setupMappings(const EventReceiverMappings& mappings){
			m_mappings = mappings;
		}

		void addMapping(const EventType& eventType, const std::function<void()>& onUpdateFunc){
			m_mappings.insert({eventType, onUpdateFunc});
		}

		const EventReceiverMappings& getMappings() const{
			return m_mappings;
		}

		virtual bool dispatchEvent(const EventType& eventType){
			// check if event is mapped
			if(m_mappings.count(eventType)){
				// call function
				m_mappings[eventType]();
				return true;
			}

			// send event to other receiver
			return forwardEvent(eventType);
		}

		virtual bool forwardEvent(const EventType& eventType) = 0;

	private:
		EventReceiverMappings m_mappings;
	};

}

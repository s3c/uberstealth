// The uberstealth configuration dialog implements this interface so the individual 
// property sheets can listen to events and also trigger actions on their behalf.

#pragma once

#include <boost/foreach.hpp>
#include <iostream>
#include <HideDebugger/HideDebuggerProfile.h>
#include "ProfileEventConsumer.h"

namespace uberstealth {

class ConfigProvider {
public:
	ConfigProvider() {
		currentProfile_ = HideDebuggerProfile::readProfileFromFile(getCurrentProfileFile());
	}

	void addListener(uberstealth::ProfileEventConsumer* consumer) {
		consumers_.push_back(consumer);
	}

	// Send loadProfile event to all listeners.
	void triggerLoadEvent()	{
		BOOST_FOREACH(uberstealth::ProfileEventConsumer* consumer, consumers_) {
			consumer->loadProfile(currentProfile_);
		}
	}

	// Send flushProfile event to all listeners.
	void triggerFlushProfileEvent()	{
		BOOST_FOREACH(uberstealth::ProfileEventConsumer* consumer, consumers_) {
			consumer->flushProfile(currentProfile_);
		}
	}

	// Send global enable state changed event to all listeners.
	void triggerChangeGlobalEnableState(bool globalEnable) {
		BOOST_FOREACH(uberstealth::ProfileEventConsumer* consumer, consumers_) {
			consumer->changeGlobalEnableState(globalEnable);
		}
	}

	// Switch profile and trigger loadProfile event.
	void triggerSwitchProfile(const std::string& profileName) {
		currentProfile_ = uberstealth::HideDebuggerProfile::readProfileByName(profileName);
		triggerLoadEvent();
	}

	// Query all consumers to determine if the current profile has unchanged modifications.
	bool isProfileModified() const {
		bool modified = false;
		BOOST_FOREACH(uberstealth::ProfileEventConsumer* consumer, consumers_) {
			modified |= consumer->isProfileDirty();
		}
		return modified;
	}

	const uberstealth::HideDebuggerProfile& getCurrentProfile() const { return currentProfile_; }

private:
	std::vector<uberstealth::ProfileEventConsumer*> consumers_;
	uberstealth::HideDebuggerProfile currentProfile_;
};

}
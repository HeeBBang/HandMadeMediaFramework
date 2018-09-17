#include "EventManager.h"

EventManager::EventManager(){

}

EventManager::~EventManager(){

}



/// <summary>
/// Start Event Manager
/// </summary>
void EventManager::start(void) {
	operation = true;
	
	if (main_loop)
		return;





}

/// <summary>
/// Stop Event Manager
/// </summary>
void EventManager::stop(void) {
	operation = false;


}
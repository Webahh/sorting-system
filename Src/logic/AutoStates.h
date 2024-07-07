#pragma once

#include "logic/SOController.h"
#include <cstddef>
#include <string>

namespace so {
	namespace AutoStates {

		/**
		* Handles the sequence of dropping an item.
		* @return The next state after the item is dropped.
		*/
		SOState stateDropItem();

		/**
		* Moves the crane to the garbage dropper position.
		* @return The next state after reaching the garbage dropper position.
		*/
		SOState stateMoveToDropperGarbage();

		/**
		* Moves the crane to the left dropper position.
		* @return The next state after reaching the left dropper position.
		*/
		SOState stateMoveToDropperLeft();

		/**
		* Moves the crane to the middle dropper position.
		* @return The next state after reaching the middle dropper position.
		*/
		SOState stateMoveToDropperMiddle();

		/**
		* Moves the crane to the right dropper position.
		* @return The next state after reaching the right dropper position.
		*/
		SOState stateMoveToDropperRight();

		/**
		* Checks the color of the detected item and sets the next state based on the color.
		* @return The next state based on the detected color.
		*/
		SOState stateCheckColor();

		/**
		* Moves the crane to the color sensor position.
		* @return The next state after reaching the color sensor position.
		*/
		SOState stateMoveToColorSensor();

		/**
		* Handles the sequence of collecting an item.
		* @return The next state after the item is collected.
		*/
		SOState stateCollectItem();

		/**
		* Checks if an item exists and sets the next state accordingly.
		* @return The next state based on the existence of an item.
		*/
		SOState stateCheckItemExists();

		/**
		* Moves the crane to the loader position.
		* @return The next state after reaching the loader position.
		*/
		SOState stateMoveToLoader();

		/**
		* Gets the current item count.
		* @return The number of items.
		*/
		int getItemCount();

		/**
		* Sets the item count.
		* @param count The number of items.
		*/
		void setItemCount(int count);

		/**
		* Gets the last detected color.
		* @return The last detected color as a string.
		*/
		const std::string& getLastDetectedColor();

		/**
		* @returns the status of the move to garbage flag.
		*/
		bool getIsMoveToGarbage();

		/**
		* Sets the move to garbage flag.
		* @param bGarbage True to set moving to garbage, false otherwise.
		*/
		void setIsMoveToGarbage(bool bGarbage);
	}
}

// No-Copyright


#include "UI/ViewModel/MVVM_LoadSlot.h"

void UMVVM_LoadSlot::InitializeSlot()
{
	// TODO: Check slot status based on load data.
	SetWidgetSwitcherIndex.Broadcast(1);
}

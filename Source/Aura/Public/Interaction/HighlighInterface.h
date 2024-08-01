// No-Copyright

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HighlighInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHighlighInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IHighlighInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// = 0 means pure function 
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};

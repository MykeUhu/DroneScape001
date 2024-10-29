#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UhuAbilitySystemLibrary.generated.h"

class UUhuOverlayWidgetController;
/**
 * 
 */
UCLASS()
class DRONESCAPE_API UUhuAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
 GENERATED_BODY()
public:

 UFUNCTION(BlueprintPure, Category="UhuAbilitySystemLibrary|WidgetController")
 static UUhuOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

};

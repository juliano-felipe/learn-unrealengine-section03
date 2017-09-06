// Project for sutdying Unreal Engine Course

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

private:

	UPROPERTY(EditAnywhere)
        ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 30.f;
	
	// owning door
	AActor* Owner = nullptr;

    // gets the total mass in kg
	float GetTotalMassOnPlate();
};

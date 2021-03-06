// Copyright Sébastien Vinel 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Return current start of reach line
	FVector GetReachLineStart();

	// Return current end of reach line
	FVector GetReachLineEnd();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



private:
	//How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	// Ray-cast and grab what it reaches
	void Grab();

	// Called when grab is released
	void Release();

	// Find atached physics handle
	void FindPhysicsHandleComponent();

	// Setup attached input component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MachineGun.generated.h"

UCLASS()
class BLOCKFRENZY_API AMachineGun : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly)
		USkeletalMeshComponent* RapidGun;

	
public:	
	// Sets default values for this actor's properties
	AMachineGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float fireSpeed;

	
protected:

	void Fire();

	virtual void setupInput(class UInputComponent* Input); //override;
		
	FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const;
};

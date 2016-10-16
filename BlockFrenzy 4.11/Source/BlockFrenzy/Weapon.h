// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Weapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLOCKFRENZY_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

		//UPROPERTY(VisibleDefaultsOnly, Category = Weapon)
		////UBaseWeapon* Gun;
		//AActor* Weapon;
		//
public:	
	// Sets default values for this component's properties
	UWeapon();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};

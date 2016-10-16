// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class BLOCKFRENZY_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Weapon;


	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float WeaponRange;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Gameplay)
		float WeaponDamage;

	void Fire();

	FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const;

	//virtual void SetupInput(class UInputComponent* Input);



	
	
};

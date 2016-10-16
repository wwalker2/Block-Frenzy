// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "EquipingCharacter.generated.h"

UCLASS()
class BLOCKFRENZY_API AEquipingCharacter : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Gun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CharacterCamera;

public:
	// Sets default values for this character's properties
	AEquipingCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		bool isGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		bool isRocketLauncher;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float WeaponRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float WeaponDamage;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward(float Val);

	void MoveRight(float Val);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void Fire();

//protected:
	FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const;
//

	
	
};

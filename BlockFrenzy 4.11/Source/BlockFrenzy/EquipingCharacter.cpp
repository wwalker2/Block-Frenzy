// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockFrenzy.h"
#include "EquipingCharacter.h"


// Sets default values
AEquipingCharacter::AEquipingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//CharacterCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterCamera"));
	//CharacterCamera->AttachParent = GetCapsuleComponent();
	//CharacterCamera->RelativeLocation = FVector(0, 0, 64.f);
	//CharacterCamera->bUsePawnControlRotation = true;

	//CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	//CharacterMesh->SetOnlyOwnerSee(true);
	//CharacterMesh->AttachParent = CharacterCamera;
	//CharacterMesh->bCastDynamicShadow = false;
	//CharacterMesh->CastShadow = false;

	Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	Gun->SetOnlyOwnerSee(true);
	Gun->bCastDynamicShadow = false;
	Gun->AttachTo(CharacterMesh, TEXT("Grip"), EAttachLocation::SnapToTargetIncludingScale, true);


	GunOffset = FVector(100.0f, 30.0f, 10.0f);
}

// Called when the game starts or when spawned
void AEquipingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipingCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AEquipingCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &AEquipingCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AEquipingCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AEquipingCharacter::TurnAtRate);

	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AEquipingCharacter::LookUpAtRate);

	InputComponent->BindAction("Fire", IE_Pressed, this, &AEquipingCharacter::Fire);

}

void AEquipingCharacter::MoveForward(float Value) {
	if (Value != 0.0f) 
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AEquipingCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// Add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AEquipingCharacter::TurnAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AEquipingCharacter::LookUpAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AEquipingCharacter::Fire()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	FVector CamLoc;
	FRotator CamRot;
	PlayerController->GetPlayerViewPoint(CamLoc, CamRot);
	const FVector ShootDir = CamRot.Vector();

	FVector StartTrace = FVector::ZeroVector;
	if (isGun == true) {
		WeaponRange = 5000.0f;
		WeaponDamage = 500000.0f;
	}

	if (PlayerController)
	{
		FRotator UnusedRot;
		PlayerController->GetPlayerViewPoint(StartTrace, UnusedRot);

		// Adjust trace so there is nothing blocking the ray between the camera and the pawn, and calculate distance from adjusted start
		StartTrace = StartTrace + ShootDir * ((GetActorLocation() - StartTrace) | ShootDir);
	}

	// Calculate endpoint of trace
	const FVector EndTrace = StartTrace + ShootDir * WeaponRange;

	// Check for impact
	const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);

	// Deal with impact
	AActor* DamagedActor = Impact.GetActor();
	UPrimitiveComponent* DamagedComponent = Impact.GetComponent();

	// If we hit an actor, with a component that is simulating physics, apply an impulse
	if ((DamagedActor != NULL) && (DamagedActor != this) && (DamagedComponent != NULL) && DamagedComponent->IsSimulatingPhysics())
	{
		DamagedComponent->AddImpulseAtLocation(ShootDir*WeaponDamage, Impact.Location);
	}
}

FHitResult AEquipingCharacter::WeaponTrace(const FVector & StartTrace, const FVector & EndTrace) const
{
	return FHitResult();
}



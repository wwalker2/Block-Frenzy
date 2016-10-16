// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockFrenzy.h"
#include "MachineGun.h"


// Sets default values
AMachineGun::AMachineGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RapidGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RapidGun"));

}

// Called when the game starts or when spawned
void AMachineGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMachineGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AMachineGun::setupInput(class UInputComponent* Input)
{
	check(Input);

	InputComponent->BindAction("Fire", IE_Pressed, this, &AMachineGun::Fire);
}

void AMachineGun::Fire() {
	//APlayerController* PlayerController = Cast<APlayerController>(GetController());
	FVector CamLoc;
	FVector CamRot;

	//const FVector ShootDir = CamRot.Vector;

}

// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockFrenzy.h"
#include "MyActorDummy.h"


// Sets default values
AMyActorDummy::AMyActorDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorDummy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorDummy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


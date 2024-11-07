// Fill out your copyright notice in the Description page of Project Settings.


#include "Receptor.h"

// Sets default values
AReceptor::AReceptor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReceptor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReceptor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AReceptor::Saltar()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Jugador empezo a saltar")));
}

void AReceptor::Disparar()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Jugador empezo a disparar")));
}

void AReceptor::Deshacer(FString _comando)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Jugador deshizo el comando: %s"), *_comando));
}


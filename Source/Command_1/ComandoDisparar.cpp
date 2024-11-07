// Fill out your copyright notice in the Description page of Project Settings.

#include "ComandoDisparar.h"
#include "Receptor.h"

// Sets default values
AComandoDisparar::AComandoDisparar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DisparoRealizado = false;

}

// Called when the game starts or when spawned
void AComandoDisparar::BeginPlay()
{
	Super::BeginPlay();
	Receptor = GetWorld()->SpawnActor<AReceptor>(AReceptor::StaticClass());
	
}

// Called every frame
void AComandoDisparar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AComandoDisparar::Ejecutar()
{
	Receptor->Disparar();
	DisparoRealizado = true;
	if (DisparoRealizado) {
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Disparo: %s"), DisparoRealizado ? TEXT("true") : TEXT("false")));
	}
}

void AComandoDisparar::Deshacer()
{
	DisparoRealizado = false;
	if (!DisparoRealizado) {
		Receptor->Deshacer("Disparar");
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Disparo: %s"), DisparoRealizado ? TEXT("true") : TEXT("false")));
	}
}


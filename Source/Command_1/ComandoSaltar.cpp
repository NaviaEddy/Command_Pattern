// Fill out your copyright notice in the Description page of Project Settings.

#include "ComandoSaltar.h"
#include "Receptor.h"

// Sets default values
AComandoSaltar::AComandoSaltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PosicionInicial = FVector(0.f, 0.f, 0.f);
}

// Called when the game starts or when spawned
void AComandoSaltar::BeginPlay()
{
	Super::BeginPlay();
	Receptor = GetWorld()->SpawnActor<AReceptor>(AReceptor::StaticClass());
}

// Called every frame
void AComandoSaltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AComandoSaltar::Ejecutar()
{
	Receptor->Saltar();
	FVector PosicionActual = PosicionInicial + FVector(0.f, 0.f, 10.f);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Empezo a saltar: %f"), PosicionActual.Z));

}

void AComandoSaltar::Deshacer()
{
	Receptor->Deshacer("Saltar");
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Dejo de saltar: %f"), PosicionInicial.Z));
}


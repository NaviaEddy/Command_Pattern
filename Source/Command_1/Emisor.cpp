// Fill out your copyright notice in the Description page of Project Settings.
#include "Emisor.h"
#include "ICommand.h"

// Sets default values
AEmisor::AEmisor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmisor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmisor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEmisor::EstablecerComando(AActor* _comando)
{
	comando = Cast<IICommand>(_comando);
}

void AEmisor::EjecutarComando()
{
	comando->Ejecutar();	
}

void AEmisor::DeshacerComando()
{
	comando->Deshacer();
}


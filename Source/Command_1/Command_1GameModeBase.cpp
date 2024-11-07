// Copyright Epic Games, Inc. All Rights Reserved.
#include "Command_1GameModeBase.h"
#include "Emisor.h"
#include "Receptor.h"
#include "ComandoDisparar.h"
#include "ComandoSaltar.h"

ACommand_1GameModeBase::ACommand_1GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Comandos = TArray<AActor*>();
	temp = 0.f;
}

void ACommand_1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	Emisor = GetWorld()->SpawnActor<AEmisor>(AEmisor::StaticClass());

	EjecutarComandoSaltar();
	EjecutarComandoDisparar();

}

void ACommand_1GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	temp += DeltaTime;

	if (temp >= 5.f)
	{
		DeshacerComando();
		temp = 0.f;
	}
}

void ACommand_1GameModeBase::EjecutarComandoSaltar()
{
	if (Emisor)
	{
		CSaltar = GetWorld()->SpawnActor<AComandoSaltar>(AComandoSaltar::StaticClass());
		Emisor->EstablecerComando(CSaltar);
		Emisor->EjecutarComando();
		Comandos.Add(CSaltar);
	}

	
}

void ACommand_1GameModeBase::EjecutarComandoDisparar()
{
	if (Emisor)
	{
		CDisparar = GetWorld()->SpawnActor<AComandoDisparar>(AComandoDisparar::StaticClass());
		Emisor->EstablecerComando(CDisparar);
		Emisor->EjecutarComando();
		Comandos.Add(CDisparar);
	}

}

void ACommand_1GameModeBase::DeshacerComando()
{
	if (Comandos.Num() > 0)
	{
		UltimoComando = Comandos.Pop();
		Emisor->EstablecerComando(UltimoComando);
		Emisor->DeshacerComando();
	}

}

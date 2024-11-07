// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Command_1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class COMMAND_1_API ACommand_1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACommand_1GameModeBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, Category="Game mode")
	class AEmisor* Emisor;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class AReceptor* Receptor;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class AComandoSaltar* CSaltar;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class AComandoDisparar* CDisparar;

	void EjecutarComandoSaltar();
	void EjecutarComandoDisparar();
	void DeshacerComando();

private:
	AActor* UltimoComando;
	TArray<AActor*> Comandos;
	FTimerHandle TimerHandle;
	float temp;

};

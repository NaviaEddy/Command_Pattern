// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Emisor.generated.h"

UCLASS()
class COMMAND_1_API AEmisor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmisor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	class IICommand* comando;

public:
	void EstablecerComando(AActor* _comando);
	void EjecutarComando();
	void DeshacerComando();

};

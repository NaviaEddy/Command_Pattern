// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ICommand.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComandoDisparar.generated.h"

UCLASS()
class COMMAND_1_API AComandoDisparar : public AActor, public IICommand
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComandoDisparar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Ejecutar() override;
	void Deshacer() override;

private:
	class AReceptor* Receptor;
	bool DisparoRealizado;

};

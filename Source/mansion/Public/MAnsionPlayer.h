// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MAnsionPlayer.generated.h"

UCLASS()
class MANSION_API AMAnsionPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMAnsionPlayer();


private:
		// INPUT FUNCTIONS	
	UFUNCTION()
		void moveFrontBack(float value);
	UFUNCTION()
		void moveRightLeft(float value);
	UFUNCTION()
		void mouseYaw(float value);
	UFUNCTION()
		void mousePitch(float value);

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ITEMS
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UCameraComponent* cameraPlayer;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};

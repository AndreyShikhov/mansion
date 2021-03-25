// Fill out your copyright notice in the Description page of Project Settings.


#include "MAnsionPlayer.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMAnsionPlayer::AMAnsionPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//camera
	cameraPlayer = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraPlayer->SetupAttachment(GetCapsuleComponent());
	cameraPlayer->SetRelativeLocation(FVector( 0.0f, 0.0f, 0.0f));

}


// Called when the game starts or when spawned
void AMAnsionPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void AMAnsionPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

// Called to bind functionality to input
void AMAnsionPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("moveFrontBack"), this, &AMAnsionPlayer::moveFrontBack);
	PlayerInputComponent->BindAxis(TEXT("moveRightLeft"), this, &AMAnsionPlayer::moveRightLeft);
	PlayerInputComponent->BindAxis(TEXT("mouseYaw"), this, &AMAnsionPlayer::mouseYaw);
	PlayerInputComponent->BindAxis(TEXT("mousePitch"), this, &AMAnsionPlayer::mousePitch);

}

//	INPUTS

void AMAnsionPlayer::moveFrontBack(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void AMAnsionPlayer::moveRightLeft(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void AMAnsionPlayer::mouseYaw(float value)
{
	AddControllerYawInput(value);
}

void AMAnsionPlayer::mousePitch(float value)
{
	
	AddControllerPitchInput(value);
}

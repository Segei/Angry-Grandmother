// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter()
{
	Health = CreateDefaultSubobject<UHealthComponent>("Health");
}

void ABaseCharacter::TakeDamage(float Damage)
{
	IDamageInterface::TakeDamage(Damage);
	Health->TakeDamage(Damage);
}

void ABaseCharacter::CharacterDead()
{
	Health->OnEmptyHealth.RemoveDynamic(this, &ABaseCharacter::CharacterDead);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if(IsValid(CharacterDeadMontage))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(CharacterDeadMontage);
	}
	OnCharacterDeath.Broadcast(this);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health->OnEmptyHealth.AddDynamic(this, &ABaseCharacter::CharacterDead);
}

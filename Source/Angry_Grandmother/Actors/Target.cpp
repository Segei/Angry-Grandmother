// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Target.h"

// Sets default values
ATarget::ATarget()
{
	DamageZone = CreateDefaultSubobject<UCustomDamageZone>("Damage Zone");
	DamageZone ->SetupAttachment(RootComponent);
}



void ATarget::TakeDamage(float damage)
{
	UE_LOG(LogTemp, Warning, TEXT("result damage %f"), damage);
}



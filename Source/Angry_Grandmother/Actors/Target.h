// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/DamageInterface.h"
#include "Component/CustomDamageZone.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class ANGRY_GRANDMOTHER_API ATarget : public AActor, public IDamageInterface
{
	GENERATED_BODY()
	
public:	
	ATarget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCustomDamageZone* DamageZone;


public:	
	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(float damage) override;
};

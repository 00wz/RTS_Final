// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EditorBoundsVisualizer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTS_FINAL_API UEditorBoundsVisualizer : public UActorComponent
{
	GENERATED_BODY()

public:
	UEditorBoundsVisualizer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bounds")
	FVector Center = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bounds")
	FVector BoxExtent = FVector(2000.f, 2000.f, 500.f);

	UFUNCTION(BlueprintCallable, Category="Bounds")
	FVector GetMax() const {return Center + BoxExtent;}

	UFUNCTION(BlueprintCallable, Category="Bounds")
	FVector GetMin() const {return Center - BoxExtent;}
	
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	void DrawBox();
		
};

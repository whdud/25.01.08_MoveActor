// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HELLO_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	// 이벤트 카운트
	int32 evCnt;
	// 총 이동 거리
	int totDist;
	// 시작 좌표
	FVector2D start;
	// 0 또는 1을 랜덤 반환
	int32 step();
	// 이동 함수
	void move();
	// 이벤트 생성
	int32 createEvent();
	//거리
	float distance(FVector2D first, FVector2D second);

};

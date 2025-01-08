#include "MyActor.h"
#include "Math/UnrealMathUtility.h"   
AMyActor::AMyActor()
{
   

    // 초기화
    start = FVector2D(0, 0);
    evCnt = 0;               // 이벤트 발생 횟수
    totDist = 0;             // 총 이동 거리
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    move();

    UE_LOG(LogTemp, Warning, TEXT("총 이동 거리: %d"), totDist);
    UE_LOG(LogTemp, Warning, TEXT("총 이벤트 발생 횟수: %d"), evCnt);
}

int32 AMyActor::step()
{
    return FMath::RandRange(0, 1);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
    return FVector2D::Distance(first, second);
}

int32 AMyActor::createEvent()
{
    return FMath::RandRange(0, 1);
}

void AMyActor::move()
{
    FVector2D CurrentPosition = start;


    for (int i = 0; i < 10; ++i)
    {
        int32 StepX = step();
        int32 StepY = step();

        FVector2D NewPosition = CurrentPosition + FVector2D(StepX, StepY);

        // 이동 거리 계산
        float Dist = distance(CurrentPosition, NewPosition);
        totDist += Dist; // 총 이동 거리 누적

        // 이벤트 발생 여부
        int32 EventOccurred = createEvent();
        if (EventOccurred)
        {
            evCnt++;
        }

        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current Position: (%f, %f), Distance: %f"),
            i + 1, NewPosition.X, NewPosition.Y, Dist);

        CurrentPosition = NewPosition;
    }
}
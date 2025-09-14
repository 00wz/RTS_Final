#include "EditorBoundsVisualizer.h"
#include "DrawDebugHelpers.h"

UEditorBoundsVisualizer::UEditorBoundsVisualizer()
{
    PrimaryComponentTick.bCanEverTick = true;           // разрешаем тик
    bTickInEditor = true;                               // тикать в редакторе
}

void UEditorBoundsVisualizer::BeginPlay()
{
    Super::BeginPlay();
}

void UEditorBoundsVisualizer::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (GetWorld() && !GetWorld()->IsGameWorld())      // рисуем только в редакторе
        DrawBox();
}

void UEditorBoundsVisualizer::DrawBox()
{
    FlushPersistentDebugLines(GetWorld());
    DrawDebugBox(GetWorld(), Center, BoxExtent, FColor::Green,
                 false, -1.f, 0, 0.f);
}
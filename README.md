EzAnimation.ue4
====

Easing/Animation plugin for UnrealEngine4

![b][ball.gif]<br>
__ByBlueprint__
![bp](ball_bp.png)<br>

__ByCode__
```cpp
auto ctx = UEzAnimationFunctionLibrary::FadeInWithScale(
  staticMeshComponent,
  2.0f /* duration */, 1.0f /* targetScale */,
  EzEaseType::EaseElasticOut);
ctx->AppendDestroy();
```

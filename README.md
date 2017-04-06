EzAnimation.ue4
====

Easing/Animation plugin for UnrealEngine4

<img src="logo.gif" width="300px" /><br>

__ByBlueprint__<br>
<img src="ball_bp.png" width="300px" /><br>

__ByCode__
```cpp
auto ctx = UEzAnimationFunctionLibrary::FadeInWithScale(
  staticMeshComponent,
  2.0f /* duration */, 1.0f /* targetScale */,
  EzEaseType::EaseElasticOut);
ctx->AppendDestroy();
```

EzAnimation.ue4
====

__Easing/Animation plugin for UnrealEngine4__

<img src="logo.gif" width="280px" /><br>
<img src="button.gif" width="280px" height="143px" /> <img src="boxes.gif" width="280px" height="143px" /> <img src="doge.gif" width="280x" height="143px" /><br>
<br><br><br>

__ByBlueprint__<br>
<img src="ball_bp.png" width="300px" /><br>

__ByCode__
```cpp
auto ctx = UEzAnimationFunctionLibrary::FadeInWithScale(
  staticMeshComponent,
  2.0f /* duration */,
  EzEaseType::EaseElasticOut);
ctx->AppendDestroy();
```

How to install
----
just copy [this](SampleProject/Plugins/EzAnimPlugin) directory to your `Plugins` directory. (make sure you have at least c++ code in your project.)

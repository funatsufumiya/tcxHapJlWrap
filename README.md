# tcxHapJlWrap

tcxOsc of [TrussC](https://trussc.org/) for Julia binding generator using [CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl). Forked from [tcxJuliaCxxWrap](https://github.com/funatsufumiya/tcxJuliaCxxWrap/).

This addon is used to create [tcxHap.jl](https://github.com/funatsufumiya/tcxHap.jl) package.

## Known Issues

- `getTexture()` is implemented as `getTexturePtr()`.
  - This returns `void*` (raw pointer,) so please cast to `CxxPtr{TrussC.Texture}` or `CxxRef{TrussC.Texture}` after call.

## About

This is not actual addon, but if you add this addon into empty project, `.dll`/`.so`/`.dylib` for Julia (extension is depending on your platform) will be generated.

## Build Instruction

See [tcxJuliaCxxWrap](https://github.com/funatsufumiya/tcxJuliaCxxWrap/) in detail.
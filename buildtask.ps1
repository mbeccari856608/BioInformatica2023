& Set-Location ./buildwasm

ninja

if($?)
{
    Write-Output "Build ok"
    Copy-Item "mbeccariBioinformatica2023emscripten.js" ../demo/demobioinformatica/src/assets/mbeccariBioinformatica2023emscripten.js
    Copy-Item "mbeccariBioinformatica2023emscripten.wasm" ../demo/demobioinformatica/src/assets/mbeccariBioinformatica2023emscripten.wasm
    & Set-Location ./../

}
else
{

}
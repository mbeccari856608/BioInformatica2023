project('mbeccariBioinformatica2023', 'cpp')

include_dirs = [
    include_directories('include')
]

sources = [
    'src/main.cpp',
    'src/seeds.cpp',
    'src/HashInfo.cpp']

wasmSources = [
    'wasm/libSources.cpp']

ntHash_proj = subproject('ntHash')
nthash_lib = ntHash_proj.get_variable('nthash_lib')
nthash_include = ntHash_proj.get_variable('include_dirs')


if meson.get_compiler('cpp').get_id() == 'emscripten'
    extra_args = [
        '-s' ,
        'EXPORTED_RUNTIME_METHODS=["cwrap"]',
        '-s',
        'LINKABLE=1',
        '-s',
        'EXPORT_ALL=1'
        ]
else
    extra_args = []
endif


executable(
    'mbeccariBioinformatica2023',
    sources,
    link_with  : nthash_lib,
    include_directories: [nthash_include, include_dirs])

executable(
    'mbeccariBioinformatica2023emscripten',
    wasmSources,
    cpp_args: extra_args,
    link_args : extra_args,
    link_with  : nthash_lib,
    include_directories: [nthash_include, include_dirs])
project('mbeccariBioinformatica2023', 'cpp')

include_dirs = [
    include_directories('include')
]

sources = [ 'core/seeds.cpp' ]

wasmSources = ['wasm/libSources.cpp']

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
        'EXPORT_ALL=1',
        '--bind'
        ]
else
    extra_args = []
endif


if meson.get_compiler('cpp').get_id() != 'emscripten'
    executable(
        'mbeccariBioinformatica2023',
        [sources, 'src/main.cpp'],
        link_with  : nthash_lib,
        include_directories: [nthash_include, include_dirs])
endif

if meson.get_compiler('cpp').get_id() == 'emscripten'
    executable(
        'mbeccariBioinformatica2023emscripten',
        [sources, wasmSources],
        cpp_args: extra_args,
        link_args : extra_args,
        link_with  : nthash_lib,
        include_directories: [nthash_include, include_dirs])
endif